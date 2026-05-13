#include <stdio.h>
#include <stdbool.h>

bool isPageInFrames(int page, int frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) return true;
    }
    return false;
}


int fifo(int pages[], int n, int frames_count) {
    int frames[frames_count];
    for (int i = 0; i < frames_count; i++) frames[i] = -1;

    int faults = 0;
    int index = 0; // Tracks the "oldest" slot to replace

    for (int i = 0; i < n; i++) {
        if (!isPageInFrames(pages[i], frames, frames_count)) {
            frames[index] = pages[i];
            index = (index + 1) % frames_count; // Circular buffer logic
            faults++;
        }
    }
    return faults;
}

int lru(int pages[], int n, int frames_count) {
    int frames[frames_count];
    int last_used[frames_count];
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (!isPageInFrames(pages[i], frames, frames_count)) {
            int lru_idx = 0;
            int min_time = last_used[0];
            for (int j = 1; j < frames_count; j++) {
                if (last_used[j] < min_time) {
                    min_time = last_used[j];
                    lru_idx = j;
                }
            }
            frames[lru_idx] = pages[i];
            last_used[lru_idx] = i;
            faults++;
        } else {
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == pages[i]) {
                    last_used[j] = i;
                    break;
                }
            }
        }
    }
    return faults;
}

int optimal(int pages[], int n, int frames_count) {
    int frames[frames_count];
    for (int i = 0; i < frames_count; i++) frames[i] = -1;

    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (!isPageInFrames(pages[i], frames, frames_count)) {
            int replace_idx = -1;
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == -1) {
                    replace_idx = j;
                    break;
                }
            }
            if (replace_idx == -1) {
                int farthest = i;
                replace_idx = 0;
                for (int j = 0; j < frames_count; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                replace_idx = j;
                            }
                            break;
                        }
                    }
                    if (k == n) {
                        replace_idx = j;
                        break;
                    }
                }
            }
            frames[replace_idx] = pages[i];
            faults++;
        }
    }
    return faults;
}

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;

    printf("FIFO faults: %d\n", fifo(pages, n, frames));
    printf("LRU faults: %d\n", lru(pages, n, frames));
    printf("Optimal faults: %d\n", optimal(pages, n, frames));

    return 0;
}

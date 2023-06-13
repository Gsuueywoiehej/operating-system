#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int frames[MAX_FRAMES];
int page_faults = 0;

bool is_page_in_frames(int page) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

int get_lru_frame_index(int* access_times) {
    int lru_index = 0;
    for (int i = 1; i < MAX_FRAMES; i++) {
        if (access_times[i] < access_times[lru_index]) {
            lru_index = i;
        }
    }
    return lru_index;
}

void print_frames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

int main() {
    int pages[MAX_PAGES] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3};
    int access_times[MAX_FRAMES] = {0};

    for (int i = 0; i < MAX_PAGES; i++) {
        int page = pages[i];
        printf("Page %d: ", page);
        if (!is_page_in_frames(page)) {
            int lru_index = get_lru_frame_index(access_times);
            frames[lru_index] = page;
            access_times[lru_index] = i;
            page_faults++;
            print_frames();
        } else {
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == page) {
                    access_times[j] = i;
                    break;
                }
            }
            print_frames();
        }
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

int count = 0;

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
        count++;
    }
    h->heap[i] = item;
    print_heap(h); // 중간 상태 출력
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
            count++;
        }
        if (temp.key >= h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent];
    return item;
}

void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

void print_level(HeapType* h) {
    int level = 1;
    int count = 0;
    for (int i = 1; i <= h->heap_size; i++) {
        if (i == level) {
            printf("\n[%d]: ", level);
            level *= 2;
        }
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int main(void) {
    HeapType* heap = create();
    init(heap);
    int elements[] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };
    int size_element = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < size_element; i++) {
        element e;
        e.key = elements[i];
        insert_max_heap(heap, e);
    }

    char choice;
    while (1) {
        printf("----------------------------------\n");
        printf("|  i        :    노드 추가        |\n");
        printf("|  d        :    노드 삭제        |\n");
        printf("|  p        :    레벨별 출력      |\n");
        printf("|  c        :    종료             |\n");
        printf("----------------------------------\n");
        printf("\n\n");

        printf("메뉴 입력 : ");
        scanf(" %c", &choice);
        int input;

        if (choice == 'i') {
            printf("추가할 값 입력 : ");
            scanf("%d", &input);
            element e;
            e.key = input;
            insert_max_heap(heap, e);

            printf("노드가 이동한 횟수 : %d", count);
            count = 0;
        }
        if (choice == 'd') {
            printf("삭제할 값 입력 : ");
            scanf("%d", &input);
            element e;
            e.key = input;
            delete_max_heap(heap);
            printf("노드가 이동한 횟수 : %d", count);
            count = 0;
        }
        if (choice == 'p') {
            printf("트리 레벨별 출력 \n");
            print_level(heap);
        }
        if (choice == 'c') {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        printf("\n");
    }
    return 0;
}

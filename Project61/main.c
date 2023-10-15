#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

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

void print_heap(HeapType* h) { //과정 출력
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

void insert_max_heap(HeapType* h, element item) { //삽입
    int i;
    i = ++(h->heap_size);
    h->heap[i] = item;
    print_heap(h);
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        h->heap[i / 2] = item;
        i /= 2;
        count++;
        print_heap(h); // 중간 상태 출력
    }

}
void insert_first_heap(HeapType* h, element item) { //처음 삽입
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) { //삭제
    int parent, child;
    element item;
    print_heap(h);

    item = h->heap[1]; //최상위 노드
    h->heap[1] = h->heap[(h->heap_size)--]; //최상위 노드 삭제 -> 마지막 노드를 최상위 노드로 업데이트
    parent = 1;
    child = 2; //자식노드
    print_heap(h);

    while (child <= h->heap_size) {
        count++;
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        } //왼쪽 자식보다 오른쪽 자식이 크면 자식 업데이트
        if (h->heap[parent].key >= h->heap[child].key) break; //부모가 자식노드보다 크거나 같으면 break

        element tmp = h->heap[parent]; //부모 노드 옮김
        h->heap[parent] = h->heap[child]; //자식노드가 더 크면 자식 노드랑 부모 노드 위치 바꿈
        h->heap[child] = tmp;
        parent = child;
        child *= 2;
        print_heap(h);
    }

    return item;
}



void print_level(HeapType* h) { //레벨별 출력
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
        insert_first_heap(heap, e);
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
        scanf_s(" %c", &choice);
        int input;

        if (choice == 'i') {
            printf("추가할 값 입력 : ");
            scanf_s("%d", &input);
            element e;
            e.key = input;
            insert_max_heap(heap, e);

            printf("노드가 이동한 횟수 : %d", count);
            count = 0;
        }
        if (choice == 'd') {
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
}
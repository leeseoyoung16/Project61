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
    print_heap(h); // �߰� ���� ���
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
        printf("|  i        :    ��� �߰�        |\n");
        printf("|  d        :    ��� ����        |\n");
        printf("|  p        :    ������ ���      |\n");
        printf("|  c        :    ����             |\n");
        printf("----------------------------------\n");
        printf("\n\n");

        printf("�޴� �Է� : ");
        scanf(" %c", &choice);
        int input;

        if (choice == 'i') {
            printf("�߰��� �� �Է� : ");
            scanf("%d", &input);
            element e;
            e.key = input;
            insert_max_heap(heap, e);

            printf("��尡 �̵��� Ƚ�� : %d", count);
            count = 0;
        }
        if (choice == 'd') {
            printf("������ �� �Է� : ");
            scanf("%d", &input);
            element e;
            e.key = input;
            delete_max_heap(heap);
            printf("��尡 �̵��� Ƚ�� : %d", count);
            count = 0;
        }
        if (choice == 'p') {
            printf("Ʈ�� ������ ��� \n");
            print_level(heap);
        }
        if (choice == 'c') {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        printf("\n");
    }
    return 0;
}

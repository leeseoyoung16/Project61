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

void print_heap(HeapType* h) { //���� ���
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

void insert_max_heap(HeapType* h, element item) { //����
    int i;
    i = ++(h->heap_size);
    h->heap[i] = item;
    print_heap(h);
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        h->heap[i / 2] = item;
        i /= 2;
        count++;
        print_heap(h); // �߰� ���� ���
    }

}
void insert_first_heap(HeapType* h, element item) { //ó�� ����
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) { //����
    int parent, child;
    element item;
    print_heap(h);

    item = h->heap[1]; //�ֻ��� ���
    h->heap[1] = h->heap[(h->heap_size)--]; //�ֻ��� ��� ���� -> ������ ��带 �ֻ��� ���� ������Ʈ
    parent = 1;
    child = 2; //�ڽĳ��
    print_heap(h);

    while (child <= h->heap_size) {
        count++;
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        } //���� �ڽĺ��� ������ �ڽ��� ũ�� �ڽ� ������Ʈ
        if (h->heap[parent].key >= h->heap[child].key) break; //�θ� �ڽĳ�庸�� ũ�ų� ������ break

        element tmp = h->heap[parent]; //�θ� ��� �ű�
        h->heap[parent] = h->heap[child]; //�ڽĳ�尡 �� ũ�� �ڽ� ���� �θ� ��� ��ġ �ٲ�
        h->heap[child] = tmp;
        parent = child;
        child *= 2;
        print_heap(h);
    }

    return item;
}



void print_level(HeapType* h) { //������ ���
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
        printf("|  i        :    ��� �߰�        |\n");
        printf("|  d        :    ��� ����        |\n");
        printf("|  p        :    ������ ���      |\n");
        printf("|  c        :    ����             |\n");
        printf("----------------------------------\n");
        printf("\n\n");

        printf("�޴� �Է� : ");
        scanf_s(" %c", &choice);
        int input;

        if (choice == 'i') {
            printf("�߰��� �� �Է� : ");
            scanf_s("%d", &input);
            element e;
            e.key = input;
            insert_max_heap(heap, e);

            printf("��尡 �̵��� Ƚ�� : %d", count);
            count = 0;
        }
        if (choice == 'd') {
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
}
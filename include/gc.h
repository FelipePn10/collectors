#include <stdio.h>
#include <stdlib.h>

typedef signed char int8;

struct Object {
    void* data;          // Dados do obj
    struct Object* next; // Ponteiro para o proximo objeto
    struct Object* ref;  // Referência para outro objeto (pode ser null)
    int marked;          // 1 = marcado, 0 = não marcado
};


typedef struct s_gc {
    Object *head;              // Ponteiro para o primeiro objeto gerenciado
    Object objects;           // Lista encadeada de objetos alocados
    size_t total_memory;     //  Total de memória alocada
    size_t object_count;    //   Contador de objetos registrados
} gc;

void gc_init(gc *gc) {
    // Inicializando os valores da estrutura GC
    gc->head = NULL;        // Nenhum objeto foi alocado ainda
    gc->total_memory = 0;   // Nenhuma memória alocada
    gc->object_count = 0;   // Nenhum objeto registrado
}

// Cria um novo objeto e pede para o GC administrar esse objeto
void *gc_alloc(gc *gc, size_t size) {
 void *obj = malloc(size);
    if (obj == NULL) {
        printf("Error");
        return NULL;
    }
    Object *new_obj = (Object *)malloc(sizeof(Object));
        if (new_obj == NULL) {
            free(obj);
            printf("Error");
            return NULL;
        }
    new_obj->data = (int *)obj;
    new_obj->next = gc->head;

    gc->head = new_obj;

    gc->object_count++;
    gc->total_memory += size;

    return obj;
};

// Responsável por identificar quais objetos na memória ainda estão em uso pelo programa
// Percorre na memória todos os objetos do Gc, verifica se há referências válidas e marca os objetos em uso
void gc_mark(Object* obj) {
    //gc->head -> [object_one] -> [object_two] -> [object_three] -> NULL;
   if (obj == NULL || obj->marked) return;
   obj->marked = 1;

   gc_mark(obj->ref);
};

// Responsável por liberar a memória dos objetos não marcados e reogarnizar a lista de alocação
// void gc_sweep(gc) {
   
// };
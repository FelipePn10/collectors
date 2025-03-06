#include <stdio.h>
#include <stdlib.h>

typedef signed char int8;

struct Object {
    void *data;          // Dados do obj
    struct Object* next; // Ponteiro para o proximo objeto
};


typedef struct s_gc {
    Object *head;             // Ponteiro para o primeiro objeto gerenciado
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

void *gc_mark() {

};
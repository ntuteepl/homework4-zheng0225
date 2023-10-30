#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Order;

void sort(Order *orders, int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (orders[j].start > orders[j + 1].start) {
                Order temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int count = 0;

    
    if (scanf("%d", &n) == 1) {
        Order *orders = (Order *)malloc(n * sizeof(Order));
        for (int i = 0; i < n; i++) {
            
            scanf("%d %d", &orders[i].start, &orders[i].end);
        }

        
        sort(orders, n);

        
        int currentEnd = 0;
        for (int i = 0; i < n; i++) {
            if (orders[i].start >= currentEnd) {
                currentEnd = orders[i].end;
                count++;
            }
        }

        
        printf("%d\n", count);

        
        currentEnd = 0;
        int currentDriver = 1;
        for (int i = 0; i < n; i++) {
            if (orders[i].start >= currentEnd) {
                printf("Driver %d: %d-%d\n", currentDriver, orders[i].start, orders[i].end);
                currentEnd = orders[i].end;
                currentDriver++;
            }
        }

        free(orders);
    }

    return 0;
}

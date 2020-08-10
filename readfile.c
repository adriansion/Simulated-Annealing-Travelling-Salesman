// Sub-program to read specified node configuration files.
// Returns 2D node nodes and number of nodes found in file, all contained in nodeData struct.

#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

nodeData *readfile(char filename[]) {

    // First read is dedicated to finding the number of configured nodes.
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Could not locate text file, or text file is empty.\n");
        fclose(file);
        return NULL;

    } else {
        int lineCount = 1;
        for (int c = getc(file); c != EOF; c = getc(file)) {
            if (c == '\n') {
                lineCount++;
            }
        }
        fclose(file);

        // Remember to free the node data.
        nodeData *data_ptr = (nodeData *) malloc(sizeof(nodeData));
        data_ptr->nodes = (node *) malloc(sizeof(int) + (lineCount * sizeof(node)));


        // Keeping track of number of nodes read from file.
        data_ptr->nodeCount = lineCount;

        // Second read is dedicated to copying configured node nodes.
        file = fopen(filename, "r");

        // Writing node nodes to node data struct.
        for (int i = 0; !feof(file); i++) {
            if (i % 2 == 0) {
                fscanf(file, "%d", &(data_ptr->nodes[i / 2].xCoordinate));
            } else {
                fscanf(file, "%d", &(data_ptr->nodes[(i - 1) / 2].yCoordinate));
            }
        }
        fclose(file);
        return data_ptr;
    }
}
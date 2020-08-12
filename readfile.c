#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

// Sub-program to read specified node configuration files.
// Returns 2D node nodes and number of nodes found in file, all contained in nodeData struct.


// Reads text file with given filename, or returns null if file not found.
file_node_data *readfile(char filename[]) {

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


        // Allocating memory to new pointer for second read.
        file_node_data *data_ptr = (file_node_data *) malloc(sizeof(file_node_data));
        data_ptr->file_nodes     = (file_node *) malloc(sizeof(int) + (lineCount * sizeof(file_node)));


        // Keeping track of number of nodes read from file.
        data_ptr->file_node_count = lineCount;


        // Second read is dedicated to copying configured node coordinates.
        file = fopen(filename, "r");


        // Writing node coordinates to node data struct.
        for (int i = 0; !feof(file); i++) {

            if (i % 2 == 0) {

                fscanf(file, "%d", &(data_ptr->file_nodes[i / 2].xCoordinate));

            } else {

                fscanf(file, "%d", &(data_ptr->file_nodes[(i - 1) / 2].yCoordinate));

            }
        }

        fclose(file);
        return data_ptr;

    }
}
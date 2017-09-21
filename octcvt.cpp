#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Octconv {
    
    unsigned short shift = 24;
    unsigned long output = 0L;

public:
    Octconv (int argc, char** argv) 
    {
        if (argc != 2) 
        {
            (void)fprintf (stderr, "Usage: %s address\n", argv[0]);
            exit(-1); 
        }
        
        char* octetPtr = strtok(argv[1], ".");
        while (octetPtr != NULL)
        {
            output |= atol(octetPtr) << shift;
            shift -= 8;
            octetPtr = strtok (NULL, ".");
        } 
        
        (void) printf("%lu\n", output);
    }   
    
    ~Octconv() {}
};

int main (int argc, char** argv){
    Octconv octconv(argc, argv);
    return(0);
}

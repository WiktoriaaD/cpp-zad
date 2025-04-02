#include <stdio.h>
#include <string.h>
#include <math.h>

enum Shape {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_INVALID
};

enum Oper {
    OPER_FROM_LENGTH,
    OPER_FROM_AREA,
    OPER_FROM_PERIMETER,
    OPER_INVALID
};

struct Result{
    double length;
    double area;
    double perimeter;
};

enum Shape parse_shape(const char *shape){
    if(strcmp(shape,"square") == 0){
        return SHAPE_SQUARE;
    }
    else if(strcmp(shape,"circle") == 0)
    {
        return SHAPE_CIRCLE;
    }
    else
    {
        return SHAPE_INVALID;
    }
};

enum Oper parse_operation(const char *operation){
    if(strcmp(operation,"area") == 0){
        return OPER_FROM_AREA;
    }
    else if(strcmp(operation,"length") == 0)
    {
        return OPER_FROM_LENGTH;
    }
    else if(strcmp(operation,"perimeter") == 0)
    {
        return OPER_FROM_PERIMETER;
    }
    else
    {
        return OPER_INVALID;
    }
};

void calculate(struct Result *result, enum Shape shape, enum Oper operation, double value){
    if(shape==SHAPE_SQUARE){
        if(operation==OPER_FROM_LENGTH){
            result->length = value;
            result->area = value * value;
            result->perimeter = 4 * value;
        }
        if(operation==OPER_FROM_AREA){
            result->length = sqrt(value);
            result->area = value;
            result->perimeter = result->length * 4 ;
        }
        if(operation==OPER_FROM_PERIMETER){
            result->length = value/4;
            result->area = result->length*result->length;
            result->perimeter = value;
        }
    }
    if(shape==SHAPE_CIRCLE){
        if(operation==OPER_FROM_LENGTH){
            result->length = value;
            result->area = M_PI * value * value;
            result->perimeter = 2 * M_PI * value;;
        }
        if(operation==OPER_FROM_AREA){
            result->length = sqrt(value / M_PI);
            result->area = value;
            result->perimeter = 2 * M_PI * result->length;
        }
        if(operation==OPER_FROM_PERIMETER){
            result->length = value / (2 * M_PI);  
            result->area = M_PI * result->length * result->length;
            result->perimeter = value;
        }
    }
};

void print(const struct Result *result){
    printf("Length: %.3f\n",(result->length));
    printf("Area: %.3f\n",(result->area));
    printf("Perimeter: %.3f\n",result->perimeter);
};

int main(int argc, const char *argv[]){
    double value = atof(argv[3]);
    if(argc!=4){
        printf("Niepoprawna ilosc argumentow.\n");
        return 1;
    }

    enum Shape shape=parse_shape(argv[1]);
    if(shape == SHAPE_INVALID){
        printf("Niepoprawna figura.\n");
        return 1;
    }

    enum Oper operation =parse_operation(argv[2]);
    if(operation == OPER_INVALID){
        printf("Niepoprawna operacja.\n");
        return 1;
    }
    if(atof(argv[3]) < 0){
        printf("Niepoprawna wartosc.\n");
    }
    struct Result result;
    calculate(&result,shape,operation,value);
    print(&result);
    return 0;
};
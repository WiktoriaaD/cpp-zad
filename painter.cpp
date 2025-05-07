#include <vector>
#include <iostream>
using namespace std;

class Canvas {
public:
    Canvas(size_t w, size_t h) : width(w), height(h), grid(h, std::vector<bool>(w, false)) {}
    
    void set(size_t x, size_t y) {
        if (x < width && y < height)
            grid[y][x] = true;
    }

    void print() const {
        for (const auto& row : grid) {
            for (bool c : row) {
                std::cout << (c ? "\xE2\x96\x88" : " ");
            }
            std::cout << std::endl;
        }
    }

    size_t getWidth() const {
        return width;
    }

    size_t getHeight() const {
        return height;
    }

private:
    std::vector<std::vector<bool>> grid;
    size_t width, height;
};

class Painter {
protected:
    Canvas& canvas; /* Kompozycja */
public:
    Painter(Canvas& c) : canvas(c) {}
    virtual void paint() = 0;
};

class VerticalLinePainter : public Painter {
    private:
        size_t x;
    
    public:
        VerticalLinePainter(Canvas& c,size_t x_): Painter(c), x(x_) {}
        void paint(){
        if (x < canvas.getWidth()){    
            for(size_t y=0;y<canvas.getHeight();y++){
                canvas.set(x,y);
            }
        }
        }
};

class HorizontalLinePainter : public Painter {
    private:
        size_t y;
    
    public:
        HorizontalLinePainter(size_t y_, Canvas& c): Painter(c), y(y_) {}
        void paint(){
        if (y < canvas.getHeight()){    
            for(size_t x=0;x<canvas.getWidth();x++){
                canvas.set(x,y);
            }
        }
        }
};

class RectanglePainter : public Painter {
    private:
        size_t x1,x2,y1,y2;
    
    public:
        RectanglePainter(size_t x1_,size_t x2_,size_t y1_,size_t y2_, Canvas& c): Painter(c), x1(x1_),x2(x2_),y1(y1_),y2(y2_) {}
        void paint(){
        if (y1 < canvas.getHeight()&& y2< canvas.getHeight()){
            for(size_t x=x1;x<=x2;x++){
                if (x < canvas.getWidth()) {
                canvas.set(x,y1);
                canvas.set(x,y2);
            }
            }
        }

        if (x1 < canvas.getWidth()&& x2< canvas.getWidth()){
            for(size_t y=y1;y<=y2;y++){
                if (y < canvas.getHeight()) {
                canvas.set(x1,y);
                canvas.set(x2,y);
            }
            }
        }
        }
};
int main(){
    Canvas canvas(4,4);
    // VerticalLinePainter LinePainter(canvas,1);
    // LinePainter.paint();
    // HorizontalLinePainter HLineP(1,canvas);
    // HLineP.paint();
    RectanglePainter RLineP(1,2,1,2,canvas);
    RLineP.paint();
    canvas.print();


    return 0;
}
    
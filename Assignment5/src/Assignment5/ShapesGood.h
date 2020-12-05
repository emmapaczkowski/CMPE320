
using namespace std;

#include <string>

class Filled {
    public:
        Filled(string);
        virtual ~Filled() {};
    protected:
        string fillColor;
        virtual void fill() = 0;
};

class Labled {
    public:
        Labled(string);
        virtual ~Labled() {};

    protected:
        string textLabel;
        virtual void drawText() = 0;
};

class Shape {
    private:
        int length;
        int width;
    public: 
        Shape(int, int, string);
        virtual ~Shape() {};
        int getLength() const { return length; }
        int getWidth() const { return width; }
        virtual void draw() = 0;
    protected:
        string borderColor;
        virtual void drawBorder() = 0;
};

class Square : public Shape {
    public:
        Square(int, int, string);
        virtual void draw() {
            drawBorder();
        }
    protected:
        virtual void drawBorder();
};

class FilledSquare : public Square, Filled {
    public:
        FilledSquare(int, int, string, string);
        virtual void draw() {
            drawBorder();
            fill();
        }
    protected:
        virtual void fill();
};

class FilledTextSquare : public FilledSquare, Labled {
    public:
        FilledTextSquare(int, int, string, string, string);
        virtual void draw() {
            drawBorder();
            fill();
            drawText();
        }
    protected:
        virtual void drawText();
};

class Circle : public Shape {
    public:
        Circle(int length, int width, string borderColor) :
            Shape(length, width, borderColor) {}
        virtual void draw() {
            drawBorder();
        }
    protected:
        virtual void drawBorder();
};

class FilledCircle : public Circle, Filled {
    public:
        FilledCircle(
            int length, 
            int width,
            string borderColor, 
            string fillColor) :
        Circle(length, width, borderColor), Filled(fillColor) {};
        virtual void draw() {
            drawBorder();
            fill();
        }
    protected:
        virtual void fill();
};

class Arc : public Shape { 
    public:
        Arc(int length, int width, std::string borderColor) :
            Shape(length, width, borderColor) {}
        virtual void draw() {
            drawBorder();
        }
    protected:
        virtual void drawBorder();
};
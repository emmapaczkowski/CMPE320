#include "ShapesGood.h"
#include <iostream>


//Filled
Filled::Filled(string fillColorIn) {
    fillColor = fillColorIn;
}


//Labled
Labled::Labled(string textLableIn) {
    textLabel = textLableIn;
}


//Shape
Shape::Shape(int lengthIn, int widthIn, string borderColorIn) {
    length = lengthIn;
    width = widthIn;
    borderColor = borderColorIn;
}


//Square
Square::Square(int lengthIn, int widthIn, string borderColorIn) : Shape(lengthIn, widthIn, borderColorIn) {}

void Square::drawBorder() {
    cout <<"\nDrawing a " + borderColor + " square.";
}


//Filled Square
FilledSquare::FilledSquare(int lengthIn, int widthIn, string borderColorIn, string fillColorIn) : Square(lengthIn, widthIn, borderColorIn), Filled(fillColorIn) {}

void FilledSquare::fill() {
    cout <<" With " + fillColor + " fill.";
}

FilledTextSquare::FilledTextSquare (int lengthIn,
                                    int widthIn, 
                                    string borderColorIn, 
                                    string filledColorIn,
                                    string textLabelIn) :
                                    FilledSquare(lengthIn, widthIn, borderColorIn, filledColorIn), 
                                    Labled(textLabelIn) {};

void FilledTextSquare::drawText() {
    cout <<" Containing the text: \"" << textLabel << "!\"";
}


//Circle
void Circle::drawBorder() {
     cout <<"\nDrawing a " + borderColor + " circle.";
}

//FilledCircle
void FilledCircle::fill() {
    cout <<" With " + fillColor + " fill.";
}


//Arc
void Arc::drawBorder() {
     cout << "\nDrawing a " + borderColor + " arc.";
}
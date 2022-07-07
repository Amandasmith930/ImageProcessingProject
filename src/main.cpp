#include <iostream>

#include <math.h>
#include<string>
#include<vector>
#include <fstream>
#include "image.h"

using namespace std;
int main() {

//task 1
    Image layer1;
    layer1.ReadImage("input/layer1.tga");
    Image pattern1;
    pattern1.ReadImage("input/pattern1.tga");
    Image output;
    output.ReadImage("input/car.tga");
    output.Multiply(layer1, pattern1);
    Image example;
    example.ReadImage("examples/EXAMPLE_part1.tga");
    cout <<endl;
    cout <<  output.compare(example);
    output.WriteImage("output/part1.tga");

    //task 2
    Image layer2;
    layer2.ReadImage("input/layer2.tga");
    Image carImg;
    carImg.ReadImage("input/car.tga");
    Image output2;
    output2.ReadImage("input/layer1.tga");
    output2.Subtract(layer2, carImg);
    Image example2;
    example2.ReadImage("examples/EXAMPLE_part2.tga");
    cout <<endl;
    cout <<  output2.compare(example2);
    output2.WriteImage("output/part2.tga");

    //task 3
    Image pattern2;
    pattern2.ReadImage("input/pattern2.tga");

    Image temp;
    temp.ReadImage("input/car.tga");
    temp.Multiply(layer1, pattern2);

    Image text;
    text.ReadImage("input/text.tga");

    Image output3;
    output3.ReadImage("input/car.tga");
    output3.Screen(temp, text);

    Image example3;
    example3.ReadImage("examples/EXAMPLE_part3.tga");
    cout <<endl;
    cout <<  output3.compare(example3);
    output3.WriteImage("output/part3.tga");

    //task 4

    Image circles;
    circles.ReadImage("input/circles.tga");

    Image temp1;
    temp1.ReadImage("input/car.tga");
    temp1.Multiply(layer2, circles);

    Image output4;
    output4.ReadImage("input/car.tga");
    output4.Subtract(pattern2, temp1);

    Image example4;
    example4.ReadImage("examples/EXAMPLE_part4.tga");
    cout <<endl;
    cout <<  output4.compare(example4);
    output4.WriteImage("output/part4.tga");

    //task 5

    Image output5;
    output5.ReadImage("input/car.tga");
    //problem with overlay function
    output5.Overlay(layer1, pattern1);
    output5.WriteImage("output/part5.tga");
    Image example5;
    example5.ReadImage("examples/EXAMPLE_part5.tga");
    cout <<endl;
    cout <<  output5.compare(example5);
    output5.WriteImage("output/part5.tga");

//task 6
    Image output6;
    output6.ReadImage("input/car.tga");
    output6.AddToGreen(output6);
    Image example6;
    example6.ReadImage("examples/EXAMPLE_part6.tga");
    cout <<endl;
    cout <<  output6.compare(example6);
    output6.WriteImage("output/part6.tga");

////this seems like it works right for test 6 and 7 but i cant open the image

//task 7
    Image output7;
    output7.ReadImage("input/car.tga");
    output7.Red(output7);
    Image example7;
    example7.ReadImage("examples/EXAMPLE_part7.tga");
    cout << endl;
    cout <<  output7.compare(example7);
    output7.WriteImage("output/part7.tga");

    //task 8
    Image output8b;
    output8b.ReadImage("input/car.tga");
    output8b.Separate(output8b, 1);
    Image output8g;
    output8g.ReadImage("input/car.tga");
    output8g.Separate(output8g, 2);
    Image output8r;
    output8r.ReadImage("input/car.tga");
    output8r.Separate(output8r, 3);
    Image example8b;
    example8b.ReadImage("examples/EXAMPLE_part8_b.tga");
    Image example8g;
    example8g.ReadImage("examples/EXAMPLE_part8_g.tga");
    Image example8r;
    example8r.ReadImage("examples/EXAMPLE_part8_r.tga");
    cout << endl;
    cout <<  output8b.compare(example8b);
    output8b.WriteImage("output/part8b.tga");
    cout <<  output8g.compare(example8g);
    output8g.WriteImage("output/part8g.tga");
    cout <<  output8r.compare(example8r);
    output8r.WriteImage("output/part8r.tga");

    //task 9
    Image output9b;
    output9b.ReadImage("input/layer_blue.tga");
    Image output9g;
    output9g.ReadImage("input/layer_green.tga");
    Image output9r;
    output9r.ReadImage("input/layer_red.tga");
    Image outputFinal;
    outputFinal.ReadImage("input/layer_green.tga");
    outputFinal.Combine(output9r, output9g, output9b);
    Image example9;
    example9.ReadImage("examples/EXAMPLE_part9.tga");
    cout << endl;
    cout <<  outputFinal.compare(example9);
    outputFinal.WriteImage("output/part9.tga");

    //task 10
    Image output10;
    output10.ReadImage("input/text2.tga");
    output10.Rotate(output10);
    Image example10;
    example10.ReadImage("examples/EXAMPLE_part10.tga");
    cout << endl;
    cout <<  output10.compare(example10);
    output10.WriteImage("output/part10.tga");
    return 0;
}





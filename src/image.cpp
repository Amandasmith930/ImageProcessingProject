    //
    // Created by Admin on 3/17/22.
    //
    #include "image.h"

    void Image::ReadImage(string fileData) {
        ifstream file(fileData, ios_base::binary);
        Header headerObj;

        if (file.is_open()) {
           // cout << "open";
            file.read(&idLength, 1);
            file.read(&colorMapType, 1);
            file.read(&dataTypeCode, 1);
            file.read((char *) &colorMapOrigin, 2);
            file.read((char *) &colorMapLength,2);
            file.read(&colorMapDepth, 1);
            file.read((char *) &xOrigin, 2);
            file.read((char *) &yOrigin, 2);
            file.read((char *) &width, 2);
            file.read((char *) &height, 2);
            file.read(&bitsPerPixel, 1);
            file.read(&imageDescriptor, 1);
        }
        Pixels pixel;
       // cout << width << height;
        for(int i = 0; i < width * height; i++){
            file.read((char *)(&pixel.blue), 1);
            file.read((char *)(&pixel.green), 1);
            file.read((char *)(&pixel.red), 1);

            Pixels curr = Pixels(pixel.red, pixel.green, pixel.blue);
            pixelObj.push_back(curr);
        }

////test out the header that is loaded in
//        cout << "id length is " << (int)headerObj.idLength << endl;
//        cout << "color map type is " << (int)headerObj.colorMapType << endl;
//        cout << "Data type code is " << (int)headerObj.dataTypeCode<< endl;
//        cout << "Color map origin is " << (int)headerObj.colorMapOrigin<< endl;
//        cout << "Color map length is " << (int)headerObj.colorMapLength<< endl;
//        cout << "Color map Depth is " << (int)headerObj.colorMapDepth<< endl;
//        cout << "x origin is " <<(int) headerObj.xOrigin<< endl;
//        cout << "y origin is " << (int)headerObj.yOrigin<< endl;
//        cout << "width is " << (int)width<< endl;
//        cout << "height length is " <<(int)height<< endl;
//        cout << "Bits per pixel is " << (int)headerObj.bitsPerPixel<< endl;
//        cout << "image descriptor is " << (int)headerObj.imageDescriptor<< endl;
//
//        cout << (int)pixelObj.at(35).red;

      //  return Image(width, height, vectorPixels);
    }

    void Image::Print() {
//      //  ReadImage("car.tga");
//
//        //test header
//        cout << "id length is " << idLength << endl;
//        cout << "color map type is " << colorMapType << endl;
//        cout << "Data type code is " << dataTypeCode<< endl;
//        cout << "Color map origin is " << colorMapOrigin<< endl;
//        cout << "Color map length is " << colorMapLength<< endl;
//        cout << "Color map Depth is " << colorMapDepth<< endl;
//        cout << "x origin is " << xOrigin<< endl;
//        cout << "y origin is " << yOrigin<< endl;
//        cout << "width is " << width<< endl;
//        cout << "height length is " << height<< endl;
//        cout << "Bits per pixel is " << bitsPerPixel<< endl;
//        cout << "image descriptor is " << imageDescriptor<< endl;
//
//
    }

    void Image :: Multiply(Image &firstLayer, Image &secondLayer){
        pixelObj.clear();
        float product;
        Pixels multiply;
        if(firstLayer.width == secondLayer.width && firstLayer.height == secondLayer.height )
        for(unsigned int i = 0; i < firstLayer.width * firstLayer.height; i++){
            float firstBlue = (float) firstLayer.pixelObj[i].blue;
            firstBlue /= 255.0f;
            float secondBlue = (float) secondLayer.pixelObj[i].blue;
            secondBlue /= 255.0f;
            product = firstBlue * secondBlue * 255.0f;
            product += 0.5f;
            multiply.blue = (unsigned char) product;

            float firstGreen = (float) firstLayer.pixelObj[i].green;
            firstGreen /= 255.0f;
            float secondGreen = (float) secondLayer.pixelObj[i].green;
            secondGreen /= 255.0f;
            product = firstGreen * secondGreen * 255.0f;
            product += 0.5f;
            multiply.green = (unsigned char) product;

            float firstRed = (float) firstLayer.pixelObj[i].red;
            firstRed /= 255.0f;
            float secondRed = (float) secondLayer.pixelObj[i].red;
            secondRed /= 255.0f;
            product = firstRed  * secondRed * 255.0f;
            product += 0.5f;
            multiply.red = (unsigned char) product;

            pixelObj.push_back(multiply);
        }
    }
    void Image :: Subtract(Image &firstLayer, Image &secondLayer){
        pixelObj.clear();

        float result;
        Pixels subtract;
        if(firstLayer.width == secondLayer.width && firstLayer.height == secondLayer.height )
            for(unsigned int i = 0; i < firstLayer.width * firstLayer.height; i++){
                int firstBlue = firstLayer.pixelObj[i].blue;
                int secondBlue = secondLayer.pixelObj[i].blue;
                result = (secondBlue - firstBlue);
                if(result < 0){
                    result = 0;
                }
                subtract.blue = result;

                int firstGreen =  firstLayer.pixelObj[i].green;
                int secondGreen = secondLayer.pixelObj[i].green;
                result = (secondGreen - firstGreen);
                if(result < 0){
                    result = 0;
                }
                subtract.green = result;

                int firstRed =  firstLayer.pixelObj[i].red;
                int secondRed =  secondLayer.pixelObj[i].red;
                result = (secondRed - firstRed);
                if(result < 0){
                    result = 0;
                }
                subtract.red = result;

                pixelObj.push_back(subtract);
            }

    }

    void Image :: Screen(Image &firstLayer, Image &secondLayer){
        pixelObj.clear();

        float result;
        Pixels screen;
        if(firstLayer.width == secondLayer.width && firstLayer.height == secondLayer.height )
            for(unsigned int i = 0; i < firstLayer.width * firstLayer.height; i++){
                float firstBlue = (float) firstLayer.pixelObj[i].blue;
                firstBlue /= 255.0f;
                float secondBlue = (float) secondLayer.pixelObj[i].blue;
                secondBlue /= 255.0f;
                result = (1 - (1 - firstBlue) * (1-secondBlue)) * 255.0f;
                result += 0.5f;
                screen.blue = (unsigned char)result;

                float firstGreen = (float) firstLayer.pixelObj[i].green;
                firstGreen /= 255.0f;
                float secondGreen = (float) secondLayer.pixelObj[i].green;
                secondGreen /= 255.0f;
                result = (1 - (1 - firstGreen) * (1-secondGreen)) * 255.0f;
                result += 0.5f;
                screen.green = (unsigned char)result;

                float firstRed = (float) firstLayer.pixelObj[i].red;
                firstRed /= 255.0f;
                float secondRed = (float) secondLayer.pixelObj[i].red;
                secondRed /= 255.0f;
                result = (1 - (1 - firstRed) * (1-secondRed)) * 255.0f;
                result += 0.5f;
                screen.red = (unsigned char)result;

                pixelObj.push_back(screen);
            }
    }

    bool Image :: compare(Image &image){
        for(int i = 0; i < width * height; i++){
            if(pixelObj.at(i).red != image.pixelObj.at(i).red){
                return false;
            }
               if(pixelObj.at(i).green != image.pixelObj.at(i).green){
                   return false;
               }
            if(pixelObj.at(i).blue != image.pixelObj.at(i).blue){
                return false;
            }
            }
        return true;
        }

    void Image :: Overlay(Image &firstLayer, Image &secondLayer) {
        pixelObj.clear();
        float result;
        Pixels pix;
        for (int i = 0; i < width * height; i++) {
            if (secondLayer.pixelObj.at(i).blue <= 255/2) {
                float firstBlue = (float) firstLayer.pixelObj[i].blue;
                firstBlue /= 255.0f;
                float secondBlue = (float) secondLayer.pixelObj[i].blue;
                secondBlue /= 255.0f;
                result = 2 * (firstBlue * secondBlue) * 255.0f;
                result += 0.5f;
                pix.blue = (unsigned char) result;
            } else if (secondLayer.pixelObj.at(i).blue > 255/2) {
                float firstBlue = (float) firstLayer.pixelObj[i].blue;
                firstBlue /= 255.0f;
                float secondBlue = (float) secondLayer.pixelObj[i].blue;
                secondBlue /= 255.0f;
                result = (1 - 2 * (1 - firstBlue) * (1 - secondBlue)) * 255.0f;
                result += 0.5f;
                pix.blue = (unsigned char) result;
            }
            if (secondLayer.pixelObj.at(i).green <= 255/2) {
                float firstGreen = (float) firstLayer.pixelObj[i].green;
                firstGreen /= 255.0f;
                float secondGreen = (float) secondLayer.pixelObj[i].green;
                secondGreen /= 255.0f;
                result = 2 * (firstGreen * secondGreen) * 255.0f;
                result += 0.5f;
                pix.green = (unsigned char) result;
            } else if (secondLayer.pixelObj.at(i).green > 255/2) {
                float firstGreen = (float) firstLayer.pixelObj[i].green;
                firstGreen /= 255.0f;
                float secondGreen = (float) secondLayer.pixelObj[i].green;
                secondGreen /= 255.0f;
                result = (1 - 2 * (1 - firstGreen) * (1 - secondGreen)) * 255.0f;
                result += 0.5f;
                pix.green = (unsigned char) result;
            }
            if (secondLayer.pixelObj.at(i).red <= 255/2) {
                float firstRed = (float) firstLayer.pixelObj[i].red;
                firstRed /= 255.0f;
                float secondRed = (float) secondLayer.pixelObj[i].red;
                secondRed /= 255.0f;
                result = 2 * (firstRed * secondRed) * 255.0f;
                result += 0.5f;
                pix.red = (unsigned char) result;
            } else if (secondLayer.pixelObj.at(i).red > 255/2) {
                float firstRed = (float) firstLayer.pixelObj[i].red;
                firstRed /= 255.0f;
                float secondRed = (float) secondLayer.pixelObj[i].red;
                secondRed /= 255.0f;
                result = (1 - 2 * (1 - firstRed) * (1 - secondRed)) * 255.0f;
                result += 0.5f;
                pix.red = (unsigned char) result;
            }
            pixelObj.push_back(pix);
        }
    }

   //^^overlay : B <= 0,5 -> C = 2BA,  b > 0,5 -> C = 1-2(1-A)*(1-b)
   void Image :: AddToGreen(Image &img) {
      //  pixelObj.clear();
        float result;
        Pixels addGreen;
        for (unsigned int i = 0; i < width * height; i++) {
            // img.pixelObj[i].green;
            if(img.pixelObj[i].green + 200 > 255){
                img.pixelObj[i].green = 255;
            }
            else{
                img.pixelObj[i].green += 200;
            }
        }
    }
    void Image :: Red(Image &img) {
        //pixelObj.clear();
        float result;
       // Pixels multRed;
        for (unsigned int i = 0; i < width * height; i++) {
            int b = img.pixelObj[i].blue;
            img.pixelObj[i].blue = b * 0;

            int r = img.pixelObj[i].red;
            result = r * 4;
            if (result > 255){
                result = 255;
            }
            img.pixelObj[i].red = result;
        }
    }

    void Image :: Separate(Image &img, int num){
        for (unsigned int i = 0; i < width * height; i++) {
            if(num == 1){
                img.pixelObj[i].red = img.pixelObj[i].blue;
                img.pixelObj[i].green = img.pixelObj[i].blue;
            }
            else if(num == 2){
                img.pixelObj[i].blue = img.pixelObj[i].green;
                img.pixelObj[i].red = img.pixelObj[i].green;
            }
            else if(num == 3){
                img.pixelObj[i].blue = img.pixelObj[i].red;
                img.pixelObj[i].green = img.pixelObj[i].red;
            }
        }
    }
    void Image :: Combine(Image &img, Image &img1, Image &img2) {
        for (unsigned int i = 0; i < width * height; i++) {
                pixelObj[i].red = img.pixelObj[i].red;
                pixelObj[i].green = img1.pixelObj[i].green;
                pixelObj[i].blue = img2.pixelObj[i].blue;
        }
    }
    void Image :: Rotate(Image &img) {
        int size = width * height;
        unsigned char tempRed;
        unsigned char tempGreen;
        unsigned char tempBlue;
        for (unsigned int i = 0; i < size/2; i++) {
            tempRed = img.pixelObj[i].red;
            img.pixelObj[i].red = img.pixelObj[size-i-1].red;
            img.pixelObj[size-i-1].red = tempRed;

            tempBlue = img.pixelObj[i].blue;
            img.pixelObj[i].blue = img.pixelObj[size-i-1].blue;
            img.pixelObj[size-i-1].blue = tempBlue;

            tempGreen = img.pixelObj[i].green;
            img.pixelObj[i].green = img.pixelObj[size-i-1].green;
            img.pixelObj[size-i-1].green = tempGreen;
        }
    }

 void Image :: WriteImage(const char *output) {
        ofstream outFile(output, ios_base::binary);

        outFile.write(&idLength, 1);
        outFile.write(&colorMapType, 1);
        outFile.write(&dataTypeCode, 1);
        outFile.write((char *) &colorMapOrigin, 2);
        outFile.write((char *) &colorMapLength,2);
        outFile.write(&colorMapDepth, 1);
        outFile.write((char *) &xOrigin, 2);
        outFile.write((char *) &yOrigin, 2);
        outFile.write((char *) &width, 2);
        outFile.write((char *) &height, 2);
        outFile.write(&bitsPerPixel, 1);
        outFile.write(&imageDescriptor, 1);

        for (int i = 0; i < width * height; i++) {
            outFile.write((char *) (&pixelObj.at(i).blue), 1);
            outFile.write((char *) (&pixelObj.at(i).green), 1);
            outFile.write((char *) (&pixelObj.at(i).red),1);
        }
    }
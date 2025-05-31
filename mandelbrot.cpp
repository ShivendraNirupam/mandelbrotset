#include <SDL2/SDL.h>
#include <numeric>
#include <complex>

int isInSet(std::complex<double> c){
    std::complex<double> z(0,0);


    //Increase the range for more detailed image / more time to catch slow escaping time
    for(int i = 0; i < 500; i++){
        z = std::pow(z,2) + c;
        if(std::norm(z) > 10){ // norm returns the squared magnitude if complex number 
            return i;
        }
    }

    return 0; //if this that means we are inside the mandalbrot set
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1, 1);

    for(double x = 0.0; x < 1.0; x += 0.001){
        for(double y = 0; y < 1.0; y += 0.001){
            // Linear interpolation or range mapping between -2.0 and 2.0 using x
            //Well you can also use std::lerp for(c++ 20)
            // double real = std::lerp(-2.0, 2.0, x);
            //x - [-2.0 , 2.0]
            //y - [-2.0 , 2.0]
            double real = -2.0 + (2.0 - (-2.0)) * x; 
            double imaginary = -2.0 + (2.0 - (-2.0)) * y; 

            int iters = isInSet(std::complex<double> (real, imaginary));

            if(iters == 0){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawPointF(renderer, x * 1000, y * 1000 );
            }
            else{
                SDL_SetRenderDrawColor(renderer, 10 * iters % 255, 10 * iters % 255, 10 * iters %255, 255);

                SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
            }
        }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
}
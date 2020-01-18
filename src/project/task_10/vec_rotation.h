#include <array>

bool rotation(int angle, std::array<float, 2>& vector){
    if (angle % 90 == 0){
        int rot = (angle / 90) % 4;
        if (rot == 2 || rot == 3)
            vector[0] *= -1;
        if (rot == 1 || rot == 2 )
            vector[1] *= -1;
        return 1;
    }
    else
        return 0;
}
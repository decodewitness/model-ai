const int coefficients = 640000;

typedef struct Circle {

    // circle structure -- center formula
    std::string label;
    float circle = 1.00;    // scale in dimension
    float size_radius = 2;  // 2 = (unit)
    float degrees = 360.00; // as read from a scale are a size in quantum measure
    float degree[360];      // must be initialized
    void float_degrees() {  // used to initialize the readings on all the 360 degrees into a maximum of 2.00, and minus of 0.00, with 1.0 = nominal
        for (int i=359; i >= 0; i++) {
            degree[i] = 1.00;
        }
    };

    float circumference = 2 * 3.14159265359 * size_radius; // interpolation square
    float measured_coefficients[3] = { 1.000, 1.000, 1.000 };   // 0.5 on all sides "0.5->(-/+)<-0.5" // i=1+1 * 3; // 0=x;1=y;2=z;   // actual size of the "sphere" = 2 in diameter on all sides
    float radius_measure = measured_coefficients[0] / 2;;	// (unit) half the width of a circle in the scale of formula: "(x-axis*0.50) + (-x-axis*0.50)" scale in measures
    float radius = measured_coefficients[0] / 2;    // essentially divided by 2...
    float diameters = measured_coefficients[0];
    float center[3] = { 0.00, 0.00, 0.00 };	// x,y,z coordinates
    float diameter_measure = 2.0 * radius;	        // (unit) measures
    float integral_number_of_geometry_on_all_sides = 6.66 * 6.66 * 6.66; // total measures of the spherical object
    void geometry_in_circle() {

    }

    // coordinates for the x, y, z planes
    float *x=(center+0);    // coordinates (x)
    float *y=(center+1);    // coordinates (y)
    float *z=(center+2);    // coordinates (z)
    //axis
    float x_axis_length;
    float y_axis_length;
    float z_axis_length;
    float inverted_x_axis[coefficients];
    float inverted_y_axis[coefficients];
    float inverted_z_axis[coefficients];
    // interpolation
    float hypercoefficientsX[coefficients];    // extra plane X in a dynamic scale
    float hypercoefficientsY[coefficients];    // extra plane Y in a dynamic scale
    float hypercoefficientsZ[coefficients];    // extra plane Z in a dynamic scale
    float prevsX[coefficients];    // previous X's in a virtual plane
    float prevsY[coefficients];    // previous Y's in a virtual plane
    float prevsZ[coefficients];    // previous Z's in a virtual plane
    // float circumreference = 2.00 * 3.14159265359 * radius;	// line around the cirle
    float unit = 1;
    float mass_object = 1.00;   // wholeness of the mass
    float weight_object = 1.00; // weight of the measure
    // dots || pixel
    float point[coefficients][3] = { 0.00, 0.00, 0.00 };  // point inside, at the surface, or outside of the object
    float dotsize[coefficients] = { 1.00 };       // size of points for tiny measures

    // (1 + Square root of√5)/2     // exponentiation
    float golden_ratio() {
        float ratios = 1.00 + (5.00 / (5.00*5.00/2.00));
    return ratios;
    };// (1 + Square root of√5)/2     // exponentiation 
    // golden ratios

    float phi_ratio, phi = golden_ratio();  // (unit) measures inside algorithm

    // measuring instruments against a sphere
    void measured_against_sphere(float x_cords[2], float y_cords[2], float z_cords[2]) {

    };
    // measuring instruments against another circle's diameter in length as measure
    void measured_against_diameter(float d) {

    };
    // measuring against another circle's circumreference number
    void measured_against_circumreference(float c) {

    };
};
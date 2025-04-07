export module BasicPlane.Figures; // keywords export module marks this as a primary module interface unit

export struct Point
{
    int x{};
    int y{};
};


export struct Rectangle // make this struct visible to importers
{
    Point ul{};
    Point lr{};
};

// These functions are declared, but will
// be defined in a module implementation file
export int area(const Rectangle& r);
export int height(const Rectangle& r);
export int width(const Rectangle& r);
//
// Created by helywin on 2020/7/12.
//

class point
{
public:
    constexpr point() noexcept:
            mX(0), mY(0)
    {}

    constexpr point(double x, double y) noexcept:
            mX(x), mY(y)
    {}

    constexpr double x() const noexcept
    { return mX; }

    constexpr double y() const noexcept
    { return mY; }

    constexpr void setX(double x) noexcept
    { mX = x; }

    constexpr void setY(double y) noexcept
    { mY = y; }

private:
    double mX, mY;
};

constexpr point mid_point(const point &p1, const point &p2) noexcept
{
    return {
            (p1.x() + p2.x()) / 2,
            (p1.y() + p2.y()) / 2
    };
}

constexpr point switch_xy(const point &p) noexcept
{
    point pr;
    pr.setX(p.y());
    pr.setY(p.x());
    return pr;
}

int main()
{
    constexpr point p1(1, 2);
    constexpr auto ps1 = switch_xy(p1);
    constexpr point p2(3, 4);
    constexpr auto mid = mid_point(ps1, p2);
    point p3(1, 2);

}
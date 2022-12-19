#include <iostream>

using namespace std;

void swapValues(float& a, float& b);
bool myFunction(float x, float& y);
float setValue(const char[]);

int main()
{
    float a, b, h, y, yMax, xMax, yMin, xMin;
    int n;

    a = setValue("a");

    b = setValue("b");

    n = setValue("n");

    if (b < a)
    {
        swapValues(a, b);
    }

    h = (b - a) / n;

    while (true && n >= 0)
    {
        if (myFunction(a, y))
        {
            /*yMin = y;
            yMax = y;

            xMin = a;
            xMax = a;*/

            yMin = yMax = y;
            xMin = xMax = a;

            cout << "\n x = " << a << "\t y =" << y << endl;
            break;
        }
        a += h;
        n--;
    }

    for (int i = 1; i <= n; i++)
    {
        float x = a + i * h;
        cout << "\n x = " << x;
        if (myFunction(x, y))
        {
            cout << "\t y =" << y << endl; // Вибір нового мінімума та максимума

            if (y > yMax)
            {
                yMax = y;
                xMax = x;
            }
            else if (y < yMin)
            {
                yMin = y;
                xMin = x;
            }

        }
        else
        {
            cout << "\tFunction is undefined\n";
        }
    }
    if (n >= 0)
    {
        cout << "yMin = " << yMin << "\t when x = " << xMin << endl;
        cout << "yMax = " << yMax << "\t when x = " << xMax << endl;
    }
    else
    {
        cout << "All interval is incorrect";
    }
}

void swapValues(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

bool myFunction(float x, float& y)
{
    if (x >= -3 && x <= -1)
    {
        y = asin(x + 2) + (x * x);
        return true;
    }

    return false;
}

float setValue(const char v[])
{
    int error;
    float value;
    do
    {
        error = 0;
        cout << "Please enter " << v << " = ";
        cin >> value;
        if (cin.fail())
        {
            cout << "Please enter a valid number" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
    } while (error == 1);

    return value;
}
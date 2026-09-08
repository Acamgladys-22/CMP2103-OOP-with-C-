#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

double squaredDistance(Point first, Point second)
{
    double xDifference = first.x - second.x;
    double yDifference = first.y - second.y;
    return xDifference * xDifference + yDifference * yDifference;
}

int main()
{
    Point center;
    int bufferCount, pointCount;
    double bufferRadii[100];
    Point points[100];
    int index;

    printf("Enter the center point coordinates (x y): ");
    scanf("%lf %lf", &center.x, &center.y);

    printf("Enter the number of buffers (maximum 100): ");
    scanf("%d", &bufferCount);

    if (bufferCount < 1 || bufferCount > 100)
    {
        printf("The number of buffers must be between 1 and 100.\n");
        return 1;
    }

    for (index = 0; index < bufferCount; ++index)
    {
        printf("Enter radius for buffer %d: ", index + 1);
        scanf("%lf", &bufferRadii[index]);
    }

    printf("Enter the number of points (maximum 100): ");
    scanf("%d", &pointCount);

    if (pointCount < 1 || pointCount > 100)
    {
        printf("The number of points must be between 1 and 100.\n");
        return 1;
    }

    for (index = 0; index < pointCount; ++index)
    {
        printf("Enter coordinates for point %d (x y): ", index + 1);
        scanf("%lf %lf", &points[index].x, &points[index].y);
    }

    printf("\nPoints contained in each buffer:\n");
    for (index = 0; index < bufferCount; ++index)
    {
        double radius = bufferRadii[index];
        double radiusSquared = radius * radius;
        int pointIndex;
        int containsPoint = 0;

        printf("\nBuffer %d (radius %.2f):\n", index + 1, radius);

        for (pointIndex = 0; pointIndex < pointCount; ++pointIndex)
        {
            if (squaredDistance(center, points[pointIndex]) <= radiusSquared)
            {
                printf("Point %d (%.2f, %.2f)\n", pointIndex + 1,
                points[pointIndex].x, points[pointIndex].y);
                containsPoint = 1;
            }
        }

        if (!containsPoint)
            printf("No points fall within this buffer.\n");
    }

    return 0;
}

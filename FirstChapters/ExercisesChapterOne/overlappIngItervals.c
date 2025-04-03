#include <stdio.h>
#include <stdlib.h>

// 9. Given a list of intervals, merge all overlappint intervals.

typedef struct
{
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void *b)
{
    return((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval intervals[], int n)
{
    if (n <= 0) return;

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    Interval merged[n];
    int mergedCount = 0;

    merged[mergedCount++] = intervals[0];

    for(int i = 0; i < n; i++)
    {
        if (intervals[i].start <= merged[mergedCount - 1].end)
        {
            if (intervals[i].end > merged[mergedCount - 1].end)
            {
                merged[mergedCount - 1].end = intervals[i].end;
            }
        }
        else
        {
            merged[mergedCount++] = intervals[i];
        }
    }

    // print merged intervals
    for (int i = 0; i < mergedCount; i++)
    {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }
}

int main()
{
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {17, 28}};

    int n = sizeof(intervals) / sizeof(intervals[0]);

    mergeIntervals(intervals, n);

    return 0;
}

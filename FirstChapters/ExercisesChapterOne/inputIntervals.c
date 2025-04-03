#include <stdio.h>
#include <stdlib.h>

// 10. Write a function that will take intervals as input and takes
// care of overlapping intervals.
typedef struct
{
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void *b)
{
    return((Interval*)a)->start - ((Interval*)b)->start;
}


Interval* mergeIntervals(Interval* intervals, int* size, Interval *toMerge)
{
    // check if the interval size is zero, otherwise check if the given interval
    // overlaps with the existing ones.
    if (*size == 0)
    {
        intervals = (Interval*)malloc(++*size * sizeof(Interval));
        intervals[0].start = toMerge->start;
        intervals[0].end = toMerge->end;
    }
    else
    {
        int bool = 0;
        for (int i = 0; i < *size; i++)
        {
            if (toMerge->start <= intervals[i].end)
            {
                // this bool marks as a handled overlapping interval.
                bool = 1;

                if (toMerge->end > intervals[i].end)
                {
                    // if it overlaps and the end value of the given interval is greater than
                    // the overlapped one, then, increase the end value of the stablished interval.
                    intervals[i].end = toMerge->end;

                    // if the start value of the given interval is lesser than the stablished interval,
                    // then assign the start value of the stablished interval to the start of the 
                    // given one.
                    if (toMerge->start < intervals[i].start)
                        intervals[i].start = toMerge->start;
                }
            }
        }

        // if the given interval was not handled by the overlapping check logic, then, realloc the intervals array
        // to a greater amount of data and asign the given interval to the last position.
        if (!bool)
        {
            intervals = (Interval*)realloc(intervals, ++*size * sizeof(Interval));
            intervals[*size - 1] = *toMerge;
        }
            
    }

    // sort the new stablished array of intervals.
    qsort(intervals, *size, sizeof(Interval), compareIntervals);

    // assign a temporal array to be able to check two side overlapping.
    Interval merged[*size];
    int mergedCount = 0;

    // assign the first element int the intervals array to the temporal array.
    merged[mergedCount++] = intervals[0];

    // check for overlapping intervals, if the previous logic gived us a overlapping case
    // here we will merge it.
    for(int i = 0; i < *size; i++)
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
            // if there is no overlapping just pass the interval to the temporal array.
            merged[mergedCount++] = intervals[i];
        }
    }

    // free the older array and assign it to a new memory size, and set the
    // caller size value to the temporal array stored values.
    free(intervals);
    intervals = (Interval*)malloc(mergedCount * sizeof(Interval));
    *size = mergedCount;

    // assign the temporal values to the intervals array and print each.
    for (int i = 0; i < *size; i++)
    {
        intervals[i] = merged[i];
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
    return intervals;
}

int main()
{
    Interval* intervals;
    int lenght = 0;

    Interval inputInterval;
    int intervalsToCatch;

    printf("Hoy many intervals would you enter? ");
    scanf("%d", & intervalsToCatch);

    for (int i = 0; i < intervalsToCatch; i++)
    {
        printf("Insert the interval no. %d: ", i + 1);
        scanf("%d %d", &inputInterval.start, &inputInterval.end);
        intervals = mergeIntervals(intervals, &lenght, &inputInterval);
    }
}
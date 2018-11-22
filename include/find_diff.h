#ifndef FIND_DIFF_H
#define FIND_DIFF_H

template<typename InputIter>
InputIter find_diff(InputIter first, InputIter last)
    // Find the value in a range that is different from the others.
    // Requires a range of greater than 2 equally comparable values where one
    // value is different from all the others.
    // Returns last if range is too small or if all values are the same.
{
    if (std::distance(first, last) < 3)         // too small to have diff
        return last;

    if (*first == *(first + 1)) {
        auto it = first + 2;                    // safe due to above check
        while (it != last && *it == *first)
            ++it;
        return it;
    } else {
        return *first == *(first + 2) ? first + 1 : first;
    }
}

template<typename InputIter, typename BinCmp>
InputIter find_diff(InputIter first, InputIter last, BinCmp cmp)
{
    if (std::distance(first, last) < 3)
        return last;

    if (cmp(*first, *(first + 1))) {
        auto it = first + 2;
        while (it != last && cmp(*it, *first))
            ++it;
        return it;
    } else {
        return cmp(*first, *(first + 2)) ? first + 1 : first;
    }
}

#endif // FIND_DIFF_H

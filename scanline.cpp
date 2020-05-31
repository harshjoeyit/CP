
/*
    given an array with all values 0 size 1e5
    1e5 queries of [L, R] - which ask to add 1 to all indices between them inclusive
    find final array

    Logic - make pref array - all val = 0
            for every query 
                ++pref[i]
                --pref[r+1]

            then do the prefix sum - this is the final array  
*/
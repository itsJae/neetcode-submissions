class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        curr_a = 0
        curr_b = 0
        curr_c = 0

        for point in triplets:
            a,b,c = point

            if a <= target[0] and b <= target[1] and c <= target[2]:
                curr_a = max(curr_a, a)
                curr_b = max(curr_b, b)
                curr_c = max(curr_c, c)
                
        return [curr_a,curr_b,curr_c] == target
        
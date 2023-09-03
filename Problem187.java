class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int l = 10;
        int n = s.length();
        int a = 4;
        int al = (int) Math.pow(a, l);
        if (n <= l) {
            return new ArrayList();
        }

        Map<Character, Integer> toInt = Map.ofEntries(
            Map.entry('A', 0),
            Map.entry('C', 1),
            Map.entry('G', 2),
            Map.entry('T', 3)
        );
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = toInt.get(s.charAt(i));
        }

        int h = 0;
        Set<Integer> seen = new HashSet();
        Set<String> output = new HashSet();

        for (int start = 0; start < n - l + 1; ++start) {
            if (start != 0) {
                h = h * a + nums[start + l - 1] - nums[start - 1] * al;
            } else {
                for (int i = 0; i < l; ++i) {
                    h = h * a + nums[i];
                }
            }
            if (seen.contains(h)) {
                output.add(s.substring(start, start + l));
            }
            seen.add(h);
        }

        return new ArrayList<String>(output);
    }
}

// Rabin-Karp
// time O((N - L) L)
// space O(N - L)


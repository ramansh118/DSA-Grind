class Solution {
private:
    vector<int> findPreviousLess(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousLess(n, -1);
        stack<int> indices;

        for (int i = 0; i < n; i++) {
            while (!indices.empty() &&
                   arr[indices.top()] >= arr[i]) {
                indices.pop();
            }

            if (!indices.empty()) {
                previousLess[i] = indices.top();
            }

            indices.push(i);
        }

        return previousLess;
    }

    vector<int> findNextLessOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextLessOrEqual(n, n);
        stack<int> indices;

        for (int i = n - 1; i >= 0; i--) {
            while (!indices.empty() &&
                   arr[indices.top()] > arr[i]) {
                indices.pop();
            }

            if (!indices.empty()) {
                nextLessOrEqual[i] = indices.top();
            }

            indices.push(i);
        }

        return nextLessOrEqual;
    }

    vector<int> findPreviousgreatest(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousgreatest(n, -1);
        stack<int> indices;

        for (int i = 0; i < n; i++) {
            while (!indices.empty() &&
                   arr[indices.top()] <= arr[i]) {
                indices.pop();
            }

            if (!indices.empty()) {
                previousgreatest[i] = indices.top();
            }

            indices.push(i);
        }

        return previousgreatest;
    }

    vector<int> findNextgreatestOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextgreatestOrEqual(n, n);
        stack<int> indices;

        for (int i = n - 1; i >= 0; i--) {
            while (!indices.empty() &&
                   arr[indices.top()] < arr[i]) {
                indices.pop();
            }

            if (!indices.empty()) {
                nextgreatestOrEqual[i] = indices.top();
            }

            indices.push(i);
        }

        return nextgreatestOrEqual;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> previousLess = findPreviousLess(arr);
        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            long long leftChoices = i - previousLess[i];
            long long rightChoices = nextLessOrEqual[i] - i;

            long long contribution =
                (long long)arr[i] * leftChoices * rightChoices;

            answer += contribution;
        }

        return answer;
    }

    long long sumSubarrayMaxi(vector<int>& arr) {
        int n = arr.size();

        vector<int> previousgreatest = findPreviousgreatest(arr);
        vector<int> nextgreatestOrEqual = findNextgreatestOrEqual(arr);

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            long long leftChoices = i - previousgreatest[i];
            long long rightChoices = nextgreatestOrEqual[i] - i;

            long long contribution =
                (long long)arr[i] * leftChoices * rightChoices;

            answer += contribution;
        }

        return answer;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxi = sumSubarrayMaxi(nums);
        long long mini = sumSubarrayMins(nums);

        return maxi - mini;
    }
};
// Alternate Numbers
// https://www.naukri.com/code360/problems/alternate-numbers_6783445?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;
vector<int> alternateNumbers(vector<int> &a)
{
    int pos_count = -1;

    int neg_count = -1;

    vector<int> ans(a);

    for (int i = 0; i < a.size(); i++)
    {

        if (a[i] > 0)
        {

            pos_count++;

            ans[2 * pos_count] = a[i];
        }

        else if (a[i] < 0)
        {

            neg_count++;

            ans[(2 * neg_count) + 1] = a[i];
        }
    }

    return ans;
}

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;

        for (string email : emails) {
            string temp = "";
            int i = 0;

            // Process local name
            while (email[i] != '@') {
                if (email[i] == '+') {
                    while (email[i] != '@') {
                        i++;
                    }
                    break;
                }

                if (email[i] != '.') {
                    temp += email[i];
                }
                i++;
            }

            // Add domain
            temp += email.substr(i);

            st.insert(temp);
        }

        return st.size();
    }
};

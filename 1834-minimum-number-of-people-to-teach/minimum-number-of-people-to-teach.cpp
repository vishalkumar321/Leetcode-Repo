class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {

        unordered_set<int> problematicUsers;
        
        for (auto friendship : friendships) {
            unordered_map<int, int> firstUserLangs;
            bool canCommunicate = false;
            for (int lang : languages[friendship[0] - 1]) {
                firstUserLangs[lang] = 1;
            }
            for (int lang : languages[friendship[1] - 1]) {
                if (firstUserLangs[lang]) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematicUsers.insert(friendship[0] - 1);
                problematicUsers.insert(friendship[1] - 1);
            }
        }

        int maxUsersKnowingSameLang = 0;
        vector<int> languageCount(n + 1, 0);
        for (auto user : problematicUsers) {
            for (int lang : languages[user]) {
                languageCount[lang]++;
                maxUsersKnowingSameLang =
                    max(maxUsersKnowingSameLang, languageCount[lang]);
            }
        }

        return problematicUsers.size() - maxUsersKnowingSameLang;
    }
};

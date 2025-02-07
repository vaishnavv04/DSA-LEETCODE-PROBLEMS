class Solution {
public:
    pair<int,int> getrook(vector<vector<char>>& b)
    {
        int i = 0 , j = 0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(b[i][j]=='R')
                {
                    cout<<i<<" "<<j<<"\n";
                    return {i,j};                
                }
            }
        }
        return {};
    }
    int numRookCaptures(vector<vector<char>>& b) {
        int c = 0;
        auto [i,j] = getrook(b);
        for(int x =i;x<8;x++)
        {
            cout<<x<<" 1 "<<j<<endl;
            if(b[x][j]=='p')
            {
                c++;
                break;
            }
            else if(b[x][j]=='B')
            break;
        }
        for(int x =i;x>=0;x--)
        {
            cout<<x<<" 2 "<<j<<endl;   
            if(b[x][j]=='p')
            {
                c++;
                break;
            }
            else if(b[x][j]=='B')
            break;
        }
        for(int y =j;y<8;y++)
        {
            if(b[i][y]=='p')
            {
                c++;
                break;
            }
            else if(b[i][y]=='B')
            break;
        }
        for(int y =j;y>=0;y--)
        {
            if(b[i][y]=='p')
            {
                c++;
                break;
            }
            else if(b[i][y]=='B')
            break;
        }
        return c;
    }
};
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int arsz = 7;
int num[arsz] = {10001, 10002, 10003, 10004, 10005, 10006, 10007}, cls[arsz] = {11, 12, 11, 11, 14, 12, 13};
float g1[arsz] = {99.5, 77.9, 92.5, 89.6, 55.6, 22.1, 35.6}, g2[arsz] = {88.5, 56.5, 99.0, 56.9, 67.9, 45.9, 67.9}, g3[arsz] = {89.5, 87.5, 60.5, 90.5, 98.9, 99.2, 88.0};
char name[arsz][6] = {"Zhang", "Yang", "Liang", "Cai", "Fu", "Mao", "Zhan"};

void input(int *cata, int *start, int *end, float *sum, int *clsin, char *in)
{
    cin >> *cata;
    char ch = '\0';
    int i = 0;
    switch (*cata)
    {
    case 1:
        cin >> *start;
        cin.get();
        cin >> *end;
        break;
    case 2:
        cin >> *start;
        cin.get();
        cin >> *end;
        break;
    case 3:
    {
        cin >> ch;
        while (int(ch) != '*')
        {

            *(in + i) = ch;
            *(in + i + 1) = '\0';
            i++;
            cin >> ch;
        }
        break;
    }
    case 4:
        cin >> *sum;
        break;
    case 5:
        cin >> *clsin;
        cin.get();
        cin >> *start;
        cin.get();
        cin >> *end;
        break;
    }
}
void search(int *cata, int *start, int *end, float *sum, int *clsin, char *in)
{
    int count = 0;
    switch (*cata)
    {
    case 1:
    {
        for (int i = 0; i < arsz; i++)
        {
            if (cls[i] <= *end && cls[i] >= *start)
            {
                count++;
            }
            else
                cls[i] = 100;
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < arsz; i++)
        {
            if (num[i] <= *end && num[i] >= *start)
            {
                count++;
            }
            else
                cls[i] = 100;
        }
        break;
    }
    case 3:
    {
        bool flag = 1;
        for (int i = 0; i < arsz; i++)
        {
            int j = 0;
            while (*(in + j) != 0)
            {
                if (name[i][j] != *(in + j))
                {
                    flag = 0;
                    cls[i] = 100;
                    break;
                }
                j++;
                if (flag)
                    count++;
            }
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < arsz; i++)
        {
            if (g1[i] + g2[i] + g3[i] >= *sum)
                count++;
            else
                cls[i] = 100;
        }
        break;
    }
    case 5:
    {
        for (int i = 0; i < arsz; i++)
        {
            if (cls[i] != *clsin)
            {
                cls[i] = 100;
                continue;
            }
            else if (num[i] <= *end && num[i] >= *start)
                count++;
            else
            {
                cls[i] = 100;
                continue;
            }
        }
        break;
    }
    default:
        break;
    }
}
void sort()
{
    float ftemp, sort[arsz];
    int ntemp;
    char ctemp[6];
    for (int i = 0; i < arsz; i++)
    {
        sort[i] = cls[i] * 1000 - g1[i] - g2[i] - g3[i];
    }
    for (int i = 0; i < arsz - 1; i++)
    {
        for (int j = 0; j < arsz - 1 - i; j++)
        {
            if (sort[j] > sort[j + 1])
            {
                ntemp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = ntemp;

                ntemp = cls[j];
                cls[j] = cls[j + 1];
                cls[j + 1] = ntemp;

                ftemp = g1[j];
                g1[j] = g1[j + 1];
                g1[j + 1] = ftemp;

                ftemp = g3[j];
                g3[j] = g3[j + 1];
                g3[j + 1] = ftemp;

                ftemp = g2[j];
                g2[j] = g2[j + 1];
                g2[j + 1] = ftemp;

                ftemp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = ftemp;

                strcpy(ctemp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], ctemp);
            }
        }
    }
}
void output()
{
    for (int i = 0; i < arsz; i++)
    {
        if (cls[i] == 100)
            continue;
        cout << num[i] << " " << cls[i] << " ";
        int j = 0;
        while (name[i][j] != '\0')
        {
            cout << name[i][j];
            j++;
        }
        cout <<fixed<<setprecision(1)<< " " << g1[i] << " " << g2[i] << " " << g3[i] << endl;
    }
}

int main()
{
    int cata, start, end, clsin;
    float sum;
    char in[10];
    input(&cata, &start, &end, &sum, &clsin, in);
    search(&cata, &start, &end, &sum, &clsin, in);
    sort();
    output();
    return 0;
}

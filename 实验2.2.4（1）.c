#include<stdio.h>
enum{START,JUDGE1,JUDGE2,ERROR,DECIMALISM,HEX,OCTAL,SUFFIX1,SUFFIX2};//DECIMALISM表示十进制判断状态 ,HEX表示十六进制判断状态 ,OCTAL表示8进制 
int main(void)																		  //SUFFIX1表示后缀模式1,SUFFIX2表示后缀模式2
{
    char c;
    int state=START ,flag = 0,flag1=0,flag2=0,flag3=1,i=0;
    printf("请输入一串字符\n"); 
    while ((c=getchar())!=EOF)
    {
        if(c!='\n')
        {
        flag3 = 0;
        switch(state)
        {
            case START : flag1=0;
                if (c == '0') state = JUDGE2;
                else if (c == '-')  state = START,flag1 = 1;
                else if ((c != '-')&&(c != '0')){state = JUDGE1; goto L;}
                break;
        L:  case JUDGE1 : ((c >= '0'&&c <= '9')) ? (state = DECIMALISM) : (state = ERROR,flag = 1); break;
            case JUDGE2 : ((c == 'x')||(c == 'X'))? (flag2 = 1,state = HEX) :((c <= '7'&&c >= '0') ? (state = OCTAL) : (state = ERROR,flag = 1)) ; break ;
            case DECIMALISM :
                if(!(c >= '0'&&c <= '9')&&(c != 'u')&&(c != 'U')&&(c != 'l')&&(c != 'L')) state = ERROR,flag = 1;
                else if ((c=='u')||(c=='U')){state=SUFFIX1;	continue;}
                else if ((c=='l')||(c=='L')){state=SUFFIX2;	continue;}
                else if (c>='0'&&c<='9')  state=DECIMALISM;
                break ;
            case HEX :
                if(!((c>='0'&&c<='9')||(c>='A'&&c<='F')||(c>='a'&&c<='f'))&&(c!='u')&&(c!='U')&&(c!='l')&&(c!='L'))  state=ERROR,flag=1;
                else if((c=='u')||(c=='U')){state=SUFFIX1;	continue;}
                else if((c=='l')||(c=='L')){state=SUFFIX2;	continue;}
                else if(((c>='0'&&c<='9')||(c>='A'&&c<='F')||(c>='a'&&c<='f')))		state=HEX,flag2=0;
                break;
            case OCTAL :
                if(!(c>='0'&&c<='7')&&(c!='u')&&(c!='U')&&(c!='l')&&(c!='L'))  state=ERROR,flag=1;
                else if ((c=='u')||(c=='U')){state=SUFFIX1; continue;}
                else if ((c=='l')||(c=='L')){state=SUFFIX2; continue;}
                else if ((c>='0'&&c<='7')) state=OCTAL;
                break;
            case SUFFIX1 :
                i++;
                if(c=='l'||c=='L') continue;
                else state=ERROR,flag=1;
                break;
            case SUFFIX2 :
                i++;	
                if(c=='l'||c=='L') continue;
                else state=ERROR,flag=1;
                break;
            case ERROR : flag=1; break;
        }
    }
    else
    {
        if((flag==1)||((i>2)&&(state==SUFFIX1))||((i>1)&&(state==SUFFIX2))||(state==START)&&(flag1==1)||(flag2==1)||(flag3==1))
        {
            printf("NO\n");
            flag=0,flag1=0,flag2=0,flag3=1;
            i=0;
            state=START;
        }
        else
            printf("YES\n");			
            state=START;
            flag3=1;
            i=0;
        }		
    }
    return 0;
}

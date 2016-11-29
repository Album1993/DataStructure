//
//  Scanf.c
//  SinglelyLinkedList
//
//  Created by akka on 16/7/1.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

int Scanf(FILE *fp, char *format, ...)
{
    int *i;
    char *ch, *s;
    float *f;
    int count, k, len, n;
    int tmp;
    va_list ap;
    
    len = strlen(format);
    
    va_start(ap, format);
    
    for(count=0,k=2; k<=len; k=k+2)
    {
        while((tmp=getc(fp))!=EOF)			//Ã¯π˝À˘”–∑«Œ˜Œƒ◊÷∑˚
        {
            if((tmp>=0 && tmp<=127))
            {
                ungetc(tmp, fp);			//”ˆµΩ ◊∏ˆŒ˜Œƒ◊÷∑˚£¨Ω´¥ÀŒ˜Œƒ◊÷∑˚∑≈»Î ‰»Î¡˜
                break;
            }
        }
        
        if(tmp==EOF)
            break;
        
        if(format[k-1]=='c')				//∂¡»°◊÷∑˚
        {
            ch = va_arg(ap, char*);
            
            if(tmp!=EOF)
                count += fscanf(fp, "%c", ch);
        }
        
        if(format[k-1]=='d')				//∂¡»°’˚–Õ
        {
            i = va_arg(ap, int*);
            
            while((tmp=getc(fp))!=EOF)
            {
                if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+')
                {
                    printf("tmp:%d\n",tmp);
                    ungetc(tmp, fp);
                    break;
                }
            }
            
            if(tmp!=EOF)
            {
                printf("count1:%d\n",count);
                count += fscanf(fp, "%d", i);
                printf("count2:%d\n",count);
            }
            
        }
        
        if(format[k-1]=='f')				//∂¡»°∏°µ„–Õ
        {
            f = va_arg(ap, float*);
            
            while((tmp=getc(fp))!=EOF)
            {
                if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+'|| tmp=='.' )
                {
                    ungetc(tmp, fp);
                    break;
                }
            }
            
            if(tmp!=EOF)
                count += fscanf(fp, "%f", f);
        }
        
        if(format[k-1]=='s')				//∂¡»°◊÷∑˚¥Æ 
        {
            s = va_arg(ap, char*);
            
            while((tmp=getc(fp))!=EOF && (!isprint(tmp) || tmp==' '))
                ;
            
            n = 0;
            if(!feof(fp))
            {
                ungetc(tmp, fp);
                while((tmp=getc(fp))!=EOF)
                {
                    if(isprint(tmp) && tmp!=' ')
                        s[n++] = tmp;
                    else
                        break;	
                }
                ungetc(tmp, fp);			
            }
            
            s[n] = '\0';
            
            count++;		
        }		
    }
    
    va_end(ap);
    
    return count;
}
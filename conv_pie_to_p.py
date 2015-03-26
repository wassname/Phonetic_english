# this convert PIE fragments file to phonetic. For use in background js in photnetic chrome extention
# TODO edit the JS so it displays like wikipedia 
# that way it's intuitive and looks professional
# http://en.wikipedia.org/wiki/Wikipedia:Pronunciation_respelling_key
# will require conversion, and also js fro small caps


import csv      
respellcsv = open(r'wikipedia_respelling_table.csv','r')
resp_dict=dict()
h=[]
csv = csv.reader(respellcsv)
headers=['IPA1','VOWELS','Consonants','Stress']
for row in csv:
    if row[0]=='IPA1':
        h=row
    elif row[0] in headers:
        pass
    else:
        k=row[17].upper()
        if k:
            vals=dict()          
            for i in range(len(row)):
                k1=h[i]
                v=row[i]
                if '(' in v:
                    v=v.split('(')[0] # dirty hack
                if ',' in v:
                    v=v.split(',')[0] # dirty hack
                vals[k1]=v.upper() 
                #print row[21]
            if k in resp_dict.keys():
                print ''
                print "Repeated key", k
                print vals
                print resp_dict[k]
            resp_dict[k]=vals
        else:
            print "No '", k,"' in target spelling"

ks=resp_dict.keys()
ks.sort(key=len,reverse=True)
          
def put_accent_in_relative_places(oldstr,newstr):
    torep="'*^"
    for r in torep:
        if r in oldstr:
            i=oldstr.find(r)
            oldstr=oldstr[:i]oldstr[i+1:]
     
target_spelling='Wikipedia\xc2\xb2' # ['IPA1', 'IPA2', 'APA', 'NOAD', 'AHD', 'RHD', 'WBO', 'MECD', 'DPL', 'DPN', 'TBD', 'NBC', 'MWCD', 'COD4', 'POD', 'Cham', 'SD', 'AB', 'Dictcom', 'BBC', 'Wikipedia\xc2\xb9', 'Wikipedia\xc2\xb2', 'Examples']
import codecs
fi= open('fragments_pie.txt.','r')
fo= codecs.open('fragments.txt.','w','utf-8')
import re
cre=re.compile(r"[^'*^]") # Match all that are not ' or * or ^
for line in fi:
    if '|' in line:
       #format: word\t|\tpronounciation1, prenounciation2|\t\twordwith html accents\n'
       s=line.split('|')
       if len(s)==3:
           s=[i.strip() for i in s]
           p1,p2,p3=s
           if p2=='': # deal with no pronounciation
               p3=p1
           elif len(p2.split(' '))>1:
               for k in ks:
                   if k in p2:
                       p2=p2.replace(k,resp_dict[k][target_spelling])
               p3=p2
               #for q in p2.split(' '):
               #    if q in ks:
               #        r=resp_dict[q][target_spelling]
               #    else:
               #        print "No conversion from {} to {} for {}".format("AB",target_spelling,q)
               #        r=q
               #    p3+=' '+r
           else:
               if p2 in ks:
                   p3=resp_dict[p2][target_spelling]
               else:
                   print "No conversion from {} to {} for {}".format("AB",target_spelling,p2)
                   p3=p2
           #p3=p3.replace(' ','\u002d')
           p3+=cre.sub('',s[2]) # add on accent signs as required
           #p2=p2.replace('^','*') # change accents to no-accents
           outstr='{}\t|\t{}\t|\t{}\n'.format(s[0],s[1],p3)
           fo.write(outstr)
       else:
           print "Skipping line:", line
          

    else:
       fo.write(line)
       

for k in ks:
    print k,':',resp_dict[k][target_spelling]
 

    





    
    
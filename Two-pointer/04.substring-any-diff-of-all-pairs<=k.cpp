//max char-min char<=k

//use sorted set

sorted set g;
diff=0;
for(int i=0;int j=0;j<n;j++){   
    g.insert(a[j]);
    while(diff>k){
        g.remove(a[i]);
        diff=largest(b)-smallest(b);
        i++;
    }
    length=j-i+1
    ans=max(ans,length);
}
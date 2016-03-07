program Project1;
var len,ll,lll:array[1..230]of integer;
n,i,j,max:integer;
begin
   len[1]:=0;len[2]:=1; len[3]:=1;
   ll[1]:=1;ll[2]:=1;ll[3]:=1;
   for i:=4 to 220 do
   begin
      len[i]:=1;
      for j:=2 to i div 2 do
       if i mod j = 0 then
          if len[i]<len[j]+1 then
            len[i]:=len[j]+1;
      ll[i]:=0;
      for j:=1 to i div 2 do
      if i mod j=0 then
        if len[i]-1=len[j] then
          ll[i]:=ll[i]+ll[j];
   end;
   while not eof do
   begin
      read(n);
      writeln(len[n],' ',ll[n]);
  end;
end.

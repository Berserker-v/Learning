close all;clear;clc

%% 文本格式写入ASCII形式数据
% load trj10ms.mat
% fid= fopen('trjavp.txt','w');
% len = length(trj.avp);  avp = trj.avp;
% % 表头名称
% fprintf(fid,'%16s %16s %16s %16s %16s %16s %16s %16s %16s %16s\r\n',...
%            'pitch(rad)','roll(rad)','yaw(rad)','VE(m/s)','VN(m/s)','VU(m/s)','Lat(rad)','Lng(rad)','H(m)','Time');
% % 内容写入
% processbar(0,len);
% for i=1:len
%     for j=1:9
%         fprintf(fid,'%16.9f ',avp(i,j));
%     end
%     fprintf(fid,'%16.4f\r\n',avp(i,end));
%     if(rem(i,1000)==0), processbar(i); end
% end
% processbar;
% fclose(fid);
% return

%% 文本格式读取ASCII形式数据
% fid = fopen('trjavp.txt','r');
% fgetl(fid); % 过滤表头
% size = [10,inf];
% avp = fscanf(fid,'%f %f %f %f %f %f %f %f %f %f\r\n',size);
% avp = avp';
% fclose(fid);
% return

%% 文本格式写入HEX形式数据
% load trj10ms.mat
% fid = fopen('trjavphex.txt','w');
% avp = trj.avp;
% processbar(0,length(avp));
% for i = 1:length(avp)
%     for j=1:10
%         hexstr = num2hex(avp(i,j));
%         fprintf(fid,'%s %s %s %s %s %s %s %s ',hexstr(1:2),hexstr(3:4),hexstr(5:6),hexstr(7:8),hexstr(9:10),hexstr(11:12),hexstr(13:14),hexstr(15:16));
%     end
%     if(0==rem(i,1000)), processbar(i); end
% end
% processbar;
% fclose(fid);
% return;

%% 文本格式读取HEX形式数据
% fid = fopen('trjavphex.txt','r');
% m = 1000000;  n = 10;
% avp = zeros(n,m);
% i=1;
% while ~feof(fid)
%     hexstr = fscanf(fid,'%s %s %s %s %s %s %s %s ',8);
%     avp(i) = hex2num(hexstr);
%     i = i + 1;
% end
% row = fix(i/n);
% avp = avp'; avp(row+1:end,:) = []; 
% fclose(fid);
% return;

%% 二进制文件写入
% load trj10ms.mat
% fid = fopen('trjavp.bin','w');
% avp = trj.avp;
% for i = 1:length(avp)
%     fwrite(fid,avp(i,:),'double');
% end
% fclose(fid);

%% 二进制文件读取
% fid = fopen('trjavp.bin','r');
% fileinfo = dir('trjavp.bin');
% row = fileinfo.bytes/(8*10);
% avp = zeros(10,row);
% for i=1:row
%     avp(:,i) = fread(fid,10,'double');
% end
% avp = avp';

%% 快速读取txt文件行数
% fid = fopen('trjavp.txt','r');
% row = 0;
% while ~feof(fid)
%     % 一次性读取x个字符，计数其中回车个数
% 	% 10是回车的ASCII编码，'char'表示读取一个字符，'*'表示输出也是字符
% 	% 注意文件编码，防止乱码无法识别
%     row = row + sum(fread(fid,10000,'*char') == newline);
% end
% fclose(fid);
% return
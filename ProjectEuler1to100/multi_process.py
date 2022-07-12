#!/usr/bin/env python
# https://wiki.python.org/moin/GlobalInterpreterLock
# 还是会有内存问题?
import multiprocessing
from multiprocessing import Process,Pipe
from time import sleep

def work(conn,process_cnt,idx):
    sleep(1 * idx)
    print("Process",idx)
    conn.send(idx*idx)
    conn.close()

def prepare():
    pass

def main(process_cnt):
    prepare()
    nfuncs = range(process_cnt)
    process = []
    for i in nfuncs :
        parent_conn, child_conn = Pipe()
        p = Process(target=work, args=(child_conn,process_cnt,i))
        process.append([p,parent_conn])

    for i in nfuncs:
        process[i][0].start()

    cnt = 0
    for i in nfuncs:
        recv = process[i][1].recv()
        print(recv)
        cnt += recv
        process[i][0].join()

    print('process finished:',cnt)

main(multiprocessing.cpu_count())


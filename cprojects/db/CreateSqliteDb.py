#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#
' a test module '

__author__ = 'Michael Liao'

import sqlite3


configDb = sqlite3.connect("./config.db") 
configDb.execute("create table apn (apnid integer primary key,profileid integer not null, apnname varchar(10) not null UNIQUE, nickname text NULL)")
for t in[(0,10,'epc.com','Yu'),(1,20,'cmnet','Xu')]:
  configDb.execute("insert into apn values (?,?,?,?)", t)
configDb.commit()
configDb.execute("select apnname from apn")
#configDb.fetchall()
configDb.close()

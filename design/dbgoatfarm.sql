
----------------------------
-- C R E A T E  T A B L E -- 
----------------------------

CREATE Table Feed
(
	FeedID VARCHAR(10),
	FeedName VARCHAR(50),
	FeedType VARCHAR(20),
	Calcium DECIMAL(4,2),
	Phosphorus DECIMAL(4,2),
	Potassium DECIMAL(4,2),
	Copper DECIMAL(4,2),
	Zinc DECIMAL(4,2),

	CONSTRAINT Feed_PK PRIMARY KEY (FeedID)
);

CREATE Table Staff
(
	StaffID VARCHAR(10),
	Name VARCHAR(30) NOT NULL,
	StaffType VARCHAR(15),
	Password VARCHAR(15),
	TelNo VARCHAR(15),
	Gender VARCHAR(10),

	CONSTRAINT Staff_PK PRIMARY KEY (StaffID)
);

CREATE TABLE GoatBirth
(
	GoatID VARCHAR(6),
	GoatBreed VARCHAR(20),
	GoatGender VARCHAR(7),
	ParentGoatID VARCHAR(6),
	HealthStatus VARCHAR(10),
	GoatDOB DATE,

	CONSTRAINT GoatBirth_PK PRIMARY KEY (GoatID)
);

CREATE Table GoatShed
(
	GoatShedID VARCHAR(10),
	Title VARCHAR(20),
	Description VARCHAR(80),

	CONSTRAINT GoatShed_PK PRIMARY KEY (GoatShedID)
);

CREATE Table HealthHistory
(
	HealthHistoryID VARCHAR(10),
	GoatID VARCHAR(6),
	Sickness VARCHAR(30),
	Symptom VARCHAR(150),
	Treatment VARCHAR(150),
	DateOfRecord DATE,

	CONSTRAINT HealthHistory_PK PRIMARY KEY (HealthHistoryID),
	CONSTRAINT HealthHistory_GoatBirth_FK FOREIGN KEY (GoatID) REFERENCES GoatBirth (GoatID) ON DELETE CASCADE
);

CREATE Table MilkCollection
(
	GoatID VARCHAR(6),
	StaffID VARCHAR(10),
	GoatShedID VARCHAR(10),
	DateCollect DATE,
	Quantity DECIMAL(4,2),

  	CONSTRAINT MilkCollection_GoatBirth_FK FOREIGN KEY (GoatID) REFERENCES GoatBirth (GoatID) ON DELETE CASCADE,
	CONSTRAINT MilkCollection_Staff_FK FOREIGN KEY (StaffID) REFERENCES Staff (StaffID),
	CONSTRAINT MilkCollection_GoatShed_FK FOREIGN KEY (GoatShedID) REFERENCES GoatShed (GoatShedID)
);

CREATE Table FeedingRecord 
(
	GoatID VARCHAR(6),
	FeedID VARCHAR(10),
	StaffID VARCHAR(10),
	Quantity DECIMAL(4,2),
	FeedingTime DATETIME,	

  	CONSTRAINT FeedingRecord_GoatBirth_FK FOREIGN KEY (GoatID) REFERENCES GoatBirth (GoatID) ON DELETE CASCADE,
	CONSTRAINT FeedingRecord_Feed_FK FOREIGN KEY (FeedID) REFERENCES Feed (FeedID),
	CONSTRAINT FeedingRecord_Staff_FK FOREIGN KEY (StaffID) REFERENCES Staff (StaffID)  
);

CREATE Table GoatShedInOut
(
	GoatShedID VARCHAR(10),
	GoatID VARCHAR(6),
	CheckIn DATETIME,
  	CheckOut DATETIME,
    
  	CONSTRAINT GoatShedInOut_GoatShed_FK FOREIGN KEY (GoatShedID) REFERENCES GoatShed (GoatShedID),
  	CONSTRAINT GoatShedInOut_GoatBirth_FK FOREIGN KEY (GoatID) REFERENCES GoatBirth (GoatID) ON DELETE CASCADE
);

----------------------------------
-- I N S E R T  S T A T M E N T -- 
----------------------------------

INSERT INTO Feed VALUES ('GF001','Alfalfa Hay'.'Hay',,'16.8','2.6','24.6','9','30');
INSERT INTO Feed VALUES ('GF002','Maize Grain','Grain','0.5','3','3.9','2','21');
INSERT INTO Feed VALUES ('GF003','Sweet Potato Vine','Plant by-product','9.5','2.9','24.9','2','70');
INSERT INTO Feed VALUES ('GF004','Sunflower Seed','Oil seed','2.6','6','9.1','0.00','0.00');

INSERT INTO Staff VALUES ('S23-9786BV','Pang Jia Mei','Veterinarian','S1567250D','012-5640451','Female');
INSERT INTO Staff VALUES ('S33-49804F','Joshua Bryan','Farmer','M96021402ac','012-5631697','Male');
INSERT INTO Staff VALUES ('S48-79628S','Ooi Xue Ting','Supervisor','P@s$w0rd','018-3254508','Female');
INSERT INTO Staff VALUES ('S05-28021A','Lim Ker Xin','Administrator','KerXinAplus12','017-4528791','Female');
INSERT INTO Staff VALUES ('S05-19623F','Thum Sze Khai','Farmer','EeeewW32','012-5584694','Male');
INSERT INTO Staff VALUES ('S02-17534F','Gustaf Daren','Farmer','14125@!1','011-3278450','Male');

INSERT INTO GoatBirth VALUES ('G4B019','Katjang','Nanny','D2F213','Die',DATE'2019-04-23');
INSERT INTO GoatBirth VALUES ('W2D143','Ibex','Billy','A6K256','Healthy',DATE'2019-03-19');
INSERT INTO GoatBirth VALUES ('A1F213','Angora','Billy','S9L144','Healthy',DATE'2019-09-21');
INSERT INTO GoatBirth VALUES ('S2J186','Boer','Nanny','2M8288','Healthy',DATE'2019-12-21');
INSERT INTO GoatBirth VALUES ('D1F870','Pygmy','Billy','K1H434','Sick',DATE'2019-08-13');
INSERT INTO GoatBirth VALUES ('K1H434','Saanen','Nanny','H5H208','Healthy',DATE'2020-08-28');
INSERT INTO GoatBirth VALUES ('T0H129','Pgymy','Billy','T4D567','Sick',DATE'2020-09-12');
INSERT INTO GoatBirth VALUES ('P6F997','Pgymy','Billy','J8H432','Sick',DATE'2020-10-27');

INSERT INTO GoatShed VALUES ('GS01','Goat House A','Feed and resting place for adult goat');
INSERT INTO GoatShed VALUES ('GS02','Goat House B','Feed and resting place for adult goat');
INSERT INTO GoatShed VALUES ('GS03','Goat House C','Feed and resting place for adult goat');
INSERT INTO GoatShed VALUES ('GS04','Goat House D','Feed and resting place for adult'); 
INSERT INTO GoatShed VALUES ('GS05','Grazing Land','A field covered with grass or herbage');
INSERT INTO GoatShed VALUES ('GS06','Milking Parlor','Allow efficient milking');
INSERT INTO GoatShed VALUES ('GS07','Quarantine Pen','New goat arrival, Separation of infected one from healthy goats');

INSERT INTO HealthHistory VALUES ('H0001','G4B019','Anthrax','Dark color bloody discharge from nose, sudden fever and death','High doses of penicillin administered',DATE'2019-09-24');
INSERT INTO HealthHistory VALUES ('H0002','W2D143','Zinc Deficiency','Excessive salivating, stiff joint','Give zinc sulfate orally, avoid feeding grain',DATE'2020-01-05');
INSERT INTO HealthHistory VALUES ('H0003','D1F870','Goat Pox','Lack of appetite, Inflammation of nose and eyelids','No treatment',DATE'2020-02-14');
INSERT INTO HealthHistory VALUES ('H0004','P6F997','Parasite (roundworm)','Weight loss, rough hair coat, and diarrhea','Use antiparasitic drug',DATE'2020-10-21');
INSERT INTO HealthHistory VALUES ('H0005','P6F997','Lice','Reduced growth, skin allergy and wound','Shearing',DATE'2020-11-30');
INSERT INTO HealthHistory VALUES ('H0006','T0H129','Urinari Calculi','Tail-twitching, restlessness, anxiety','Providing a feed which contains a ammonium chloride',DATE'2020-12-05');

INSERT INTO MilkCollection VALUES ('G4B019','S02-17534F','GS01',DATE'2020-12-12','2.79');
INSERT INTO MilkCollection VALUES ('S2J186','S33-49804F','GS02',DATE'2020-12-12','2.75');
INSERT INTO MilkCollection VALUES ('K1H434','S05-19623F','GS03',DATE'2020-12-12','2.96');
INSERT INTO MilkCollection VALUES ('G4B019','S05-19623F','GS01',DATE'2020-12-13','3.91');
INSERT INTO MilkCollection VALUES ('S2J186','S02-17534F','GS02',DATE'2020-12-13','2.84');
INSERT INTO MilkCollection VALUES ('K1H434','S05-19623F','GS03',DATE'2020-12-13','3.76');
INSERT INTO MilkCollection VALUES ('G4B019','S33-49804F','GS01',DATE'2020-12-15','2.93');
INSERT INTO MilkCollection VALUES ('S2J186','S05-19623F','GS02',DATE'2020-12-15','3.12');
INSERT INTO MilkCollection VALUES ('K1H434','S33-49804F','GS03',DATE'2020-12-15','2.88');

INSERT INTO FeedingRecord VALUES ('G4B019','GF001','S33-49804F','3.60',(STR_TO_DATE('2020-11-01 12:00:01','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('W2D143','GF002','S33-49804F','3.33',(STR_TO_DATE('2020-11-01 12:00:03','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('A1F213','GF001','S33-49804F','3.40',(STR_TO_DATE('2020-11-01 12:00:10','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('S2J186','GF002','S02-17534F','3.22',(STR_TO_DATE('2020-11-01 12:00:15','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('D1F870','GF004','S02-17534F','3.10',(STR_TO_DATE('2020-11-01 12:00:18','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('K1H434','GF003','S02-17534F','3.25',(STR_TO_DATE('2020-11-01 12:00:21','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('T0H129','GF003','S05-19623F','3.56',(STR_TO_DATE('2020-11-01 12:00:22','%Y-%m-%d %H:%i:%s')));
INSERT INTO FeedingRecord VALUES ('P6F997','GF002','S05-19623F','3.44',(STR_TO_DATE('2020-11-01 12:00:23','%Y-%m-%d %H:%i:%s')));
											 
INSERT INTO GoatShedInOut VALUES ('GS01','D1F870',(STR_TO_DATE('2019-08-13 09:07:22','%Y-%m-%d %H:%i:%s')),(STR_TO_DATE('2019-08-13 10:02:32','%Y-%m-%d %H:%i:%s')));
INSERT INTO GoatShedInOut VALUES ('GS01','A1F213',(STR_TO_DATE('2020-08-13 09:10:25','%Y-%m-%d %H:%i:%s')),(STR_TO_DATE('2019-08-13 10:10:05','%Y-%m-%d %H:%i:%s')));
											 

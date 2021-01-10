CREATE Table Feed
(
	FeedID VARCHAR(10),
	FeedName VARCHAR(50),
	Type VARCHAR(20),
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
	GoatType VARCHAR(20),
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
	Sickness VARCHAR(30),
	Treatment VARCHAR(150),
	DateOfRecord DATE,
	Symptom VARCHAR(150),
	GoatID VARCHAR(6),

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
	FeedingTime DATETIME,
	Quantity DECIMAL(4,2),

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

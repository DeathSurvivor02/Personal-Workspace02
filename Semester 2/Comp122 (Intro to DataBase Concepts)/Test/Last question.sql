CREATE TABLE Assets_Types(
	asset_type_code INTEGER PRIMARY KEY,
	asset_type_description varchar2(50)

);

CREATE TABLE IT_Types(
	asset_ID INTEGER PRIMARY KEY,
	asset_type_code INTEGER,
	description varchar2(50),
	other_details varchar2(50),
	CONSTRAINT fk_asset_type FOREIGN KEY (asset_type_code) REFERENCES Assets_Types(asset_type_code)
);
CREATE TABLE Employee_Assets(
	asset_ID INTEGER,
	employee_id INTEGER,
	date_out DATE,
	date_returned DATE,
	condition_out varchar2(50),
	condition_returned varchar2(50),
	other_details varchar2(50),
	FOREIGN KEY (asset_ID) REFERENCES IT_Types(asset_ID),
	FOREIGN KEY (employee_id) REFERENCES Employees(employee_id)
);

CREATE TABLE Employees(
	first_name varchar2(50),
	last_name varchar2(50),
	department varchar2(50),
	email_address varchar2(50),
	hire_date DATE,
	other_details varchar2(50)
);
CREATE TABLE IT_Assets_Inventory(
	it_asset_inventory_ID INTEGER PRIMARY KEY,
	asset_ID INTEGER,
	inventory_date DATE,
	number_assigned INTEGER,
	number_in_stock INTEGER,
	other_details varchar2(50),
	CONSTRAINT fk_inventory_asset FOREIGN KEY (asset_ID) REFERENCES IT_Types(asset_ID)
);

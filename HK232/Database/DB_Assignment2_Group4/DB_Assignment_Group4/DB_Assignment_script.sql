drop schema e_commerce;

	create schema e_commerce;

	USE e_commerce;

	CREATE TABLE USER (
		Account_ID VARCHAR(9) unique,
		Phone_Number CHAR(10),
		Address VARCHAR(255),
		FName VARCHAR(50),
		LName VARCHAR(50),
		Boolean_Customer BOOLEAN,
		Boolean_Seller BOOLEAN,
		Seller_ID CHAR(9) UNIQUE, 
		Date_of_Birth DATE,
		Email VARCHAR(100),
		User_ID VARCHAR(255),
        Account_password varchar(255)
	);

	-- ADMIN table
	CREATE TABLE ADMIN (
	   --  ID INT AUTO_INCREMENT PRIMARY KEY,
		Account_ID VARCHAR(9) unique,
		Phone_Number CHAR(10),
		Address VARCHAR(255),
		FName VARCHAR(50),
		LName VARCHAR(50),
		Level ENUM('level_a', 'level_b', 'level_c')
	);

	-- Checking other works

	CREATE TABLE CHECKING_OTHER_WORK (
		Account_ID_Check char(9),
		Account_ID_Be_Checked char(9),
		
		primary key (Account_ID_check,Account_ID_Be_Checked),
		foreign key (Account_ID_Check) REFERENCES ADMIN(Account_ID),
		foreign key (Account_ID_Be_Checked) REFERENCES ADMIN(Account_ID)
	);


	-- PRODUCT table
	CREATE TABLE PRODUCT (
		Product_ID char(10) unique,
		Product_price DECIMAL(10, 2),
		Product_Name VARCHAR(100),
		Discount DECIMAL(5, 2),
        Discounted_Price DECIMAL(10, 2),
		Seller_ID char(9) NOT NULL,
		Description text,
		FOREIGN KEY (Seller_ID) REFERENCES USER(Seller_ID)
	);


	CREATE TABLE PRODUCT_IMAGE(
		Product_ID char(10),
		Image_URL varchar(255),
		
		primary key(Product_ID,Image_URL),
		foreign key (Product_ID) references PRODUCT(Product_ID) on delete cascade
	);

	-- CART table
	CREATE TABLE CART (
		Cart_ID char(10) PRIMARY KEY,
		Quantity INT,
		Account_ID char(9) NOT NULL,
		FOREIGN KEY (Account_ID) REFERENCES USER(Account_ID)
	);

	-- ORDER table
	CREATE TABLE ORDER_TABLE (
		Order_ID char(10) PRIMARY KEY,
		Creation_date DATE,
		Expected_date DATE,
		Cart_ID char(10) not null, 
		Seller_ID char(10),
		Address varchar(255),
		
		total_price decimal(10,2),
		
		State Enum('waiting confirmation','Packaging','Shipping','Complete'),
		FOREIGN KEY (Cart_ID) REFERENCES CART(Cart_ID),
		foreign key(Seller_ID)  references  USER(Seller_ID),
		CONSTRAINT check_dates1 CHECK (Creation_date < Expected_date)
	);


	-- ORDER_ITEM table
	CREATE TABLE ORDER_ITEM (
		Item_line_number char(10),
		Order_ID char(10),
		Quantity INT,
		Full_Discounted_Price DECIMAL(10, 2),
		Special_option VARCHAR(255) default null,
		Product_ID char(10),
		primary key(Item_line_number,Order_ID),
		FOREIGN KEY (Product_ID) REFERENCES PRODUCT(Product_ID) on delete cascade,
		FOREIGN KEY (Order_ID) REFERENCES ORDER_TABLE(Order_ID) 
	);


	-- Payment table
	CREATE TABLE PAYMENT_ORDER (
		Order_ID char(10),
		A_Payment_method varchar(100) default "In_cash",
		
		primary key(Order_ID,A_Payment_method),
		FOREIGN KEY (Order_ID) references ORDER_TABLE(Order_ID)
	);


	-- RATE table
	CREATE TABLE RATE (
		Account_ID char(9),
		Product_ID char(10),
		Rating INT,
		PRIMARY KEY (Account_ID, Product_ID),
		FOREIGN KEY (Account_ID) REFERENCES USER(Account_ID),
		FOREIGN KEY (Product_ID) REFERENCES PRODUCT(Product_ID) on delete cascade
	);

	-- ADVERTISEMENT_COMPANY table
	CREATE TABLE ADVERTISEMENT_COMPANY (
		Company_ID char(10) primary key,
		Company_Type ENUM('TV', 'YouTube', 'Social_media')
	);

	-- TV_ADVERTISEMENT table
	CREATE TABLE TV_ADVERTISEMENT (
		TV_ad_id char(10) PRIMARY KEY,
		Fee DECIMAL(10, 2),
		Time_on_site INT,
		Company_ID char(10),
		FOREIGN KEY (Company_ID) REFERENCES ADVERTISEMENT_COMPANY(Company_ID)
	);

	-- YOUTUBE_ADVERTISEMENT table
	CREATE TABLE YOUTUBE_ADVERTISEMENT (
		Youtube_ad_id char(10) PRIMARY KEY,
		Fee DECIMAL(10, 2),
		Frequency_on_video INT,
		Company_ID char(10),
		FOREIGN KEY (Company_ID) REFERENCES ADVERTISEMENT_COMPANY(Company_ID)
	);

	-- SOCIAL_MEDIA_ADVERTISEMENT table
	CREATE TABLE SOCIAL_MEDIA_ADVERTISEMENT (
		Social_media_ad_id char(10) PRIMARY KEY,
		Fee DECIMAL(10, 2),
		Frequency_on_social_media INT,
		Company_ID char(10),
		FOREIGN KEY (Company_ID) REFERENCES ADVERTISEMENT_COMPANY(Company_ID)
	);

	-- BOOKING table
	CREATE TABLE BOOKING (
		Seller_ID char(9),
		Company_ID char(10),
		PRIMARY KEY (Seller_ID, Company_ID),
		FOREIGN KEY (Seller_ID) REFERENCES USER(Seller_ID),
		FOREIGN KEY (Company_ID) REFERENCES ADVERTISEMENT_COMPANY(Company_ID) 
	);

	-- TIME table
	CREATE TABLE TIME (
		Seller_ID char(9),
		Company_ID char(10),
		Start_date DATE,
		End_date DATE,
		PRIMARY KEY (Seller_ID, Company_ID,Start_date,End_date),
		FOREIGN KEY (Seller_ID) REFERENCES USER(Seller_ID) ,
		FOREIGN KEY (Company_ID) REFERENCES ADVERTISEMENT_COMPANY(Company_ID),
		Constraint check_dates3 check (Start_date < End_date)
	);


	-- DELIVERY_COMPANY table
	CREATE TABLE DELIVERY_COMPANY (
		Company_ID char(10) PRIMARY KEY,
		Company_Name VARCHAR(100)
	);

	-- Vehicle Table
	CREATE TABLE VEHICLE (
		Vin char(17) Primary key,
		Type varchar(255),
		Capacity int default 1
	);

	-- SHIPPED_BY table
	CREATE TABLE SHIPPED_BY (
		Company_ID char(10),
		Vin VARCHAR(17),
		Order_ID char(10),
		Distance DECIMAL(10, 2),
		PRIMARY KEY (Company_ID, Vin),
		FOREIGN KEY (Company_ID) REFERENCES DELIVERY_COMPANY(Company_ID) ,
		FOREIGN KEY (Order_ID) REFERENCES ORDER_TABLE(Order_ID),
		FOREIGN KEY (Vin) REFERENCES VEHICLE(Vin) 
	);

	-- REPORT table
	CREATE TABLE REPORT (
		Order_Id char(10),
		Account_ID_admin char(9),
		Account_ID_seller char(9),
		Date DATE,
		Feedback TEXT,
		PRIMARY KEY (Order_Id, Account_ID_admin, Account_ID_seller),
		FOREIGN KEY (Account_ID_admin) REFERENCES ADMIN(Account_ID) , 
		FOREIGN KEY (Account_ID_seller) REFERENCES USER(Account_ID) ,
		FOREIGN KEY (Order_ID) REFERENCES ORDER_TABLE(Order_ID) 
	);

	-- CUSTOMER_CARE_SERVICE table
	CREATE TABLE CUSTOMER_CARE_SERVICE (
		Account_ID_admin char(9),
		Account_ID_seller char(9),
		Experience VARCHAR(255),
		PRIMARY KEY (Account_ID_admin, Account_ID_seller),
		FOREIGN KEY (Account_ID_admin) REFERENCES ADMIN(Account_ID) ,
		FOREIGN KEY (Account_ID_seller) REFERENCES USER(Seller_ID) 
	);


	-- Additional tables and relationships should be created based on the full ERD.
	CREATE TABLE PRODUCT_CART(
		Cart_ID char(10),
		Product_ID char(10),
		Quantity INT,
		
		primary key(Cart_ID,Product_ID),
		foreign key(Cart_ID) references CART(Cart_ID) ,
		foreign key(Product_ID) references PRODUCT(Product_ID) on delete cascade
	);

	CREATE TABLE sequence (
		id INT AUTO_INCREMENT PRIMARY KEY
	);
	CREATE TABLE admin_sequence (
		id INT AUTO_INCREMENT PRIMARY KEY
	);
	CREATE TABLE product_sequence (
		id INT AUTO_INCREMENT PRIMARY KEY
	);
	CREATE TABLE order_sequence (
		id INT AUTO_INCREMENT PRIMARY KEY
	);
	CREATE TABLE order_item_sequence(
		id INT AUTO_INCREMENT PRIMARY KEY
	);
	CREATE TABLE seller_id_sequence(
		id INT AUTO_INCREMENT PRIMARY KEY
	);




DELIMITER $$
CREATE TRIGGER generate_account_id
BEFORE INSERT ON USER
FOR EACH ROW
BEGIN
    INSERT INTO sequence VALUES (NULL);
    SET @last_id = LAST_INSERT_ID();
    SET NEW.Account_ID = CONCAT('ACC', LPAD(@last_id, 6, '0'));
    IF @last_id >= 100000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Account_IDs available';
    END IF;
END;
$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER generate_admin_account_id
BEFORE INSERT ON ADMIN
FOR EACH ROW
BEGIN
    INSERT INTO admin_sequence VALUES (NULL);
    SET @last_id = LAST_INSERT_ID();
    SET NEW.Account_ID = CONCAT('ADM', LPAD(@last_id, 6, '0'));
    IF @last_id > 10000 THEN
        DELETE FROM admin_sequence WHERE id = @last_id;
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Account_IDs available';
    END IF;
END;
$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER generate_product_id
BEFORE INSERT ON PRODUCT
FOR EACH ROW
BEGIN
    INSERT INTO product_sequence VALUES (NULL);
    SET @last_id = LAST_INSERT_ID();
    SET NEW.Product_ID = CONCAT('PRO', LPAD(@last_id, 7, '0'));
    IF @last_id >= 100000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Product_IDs available';
    END IF;
END;
$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER generate_order_id
BEFORE INSERT ON ORDER_TABLE
FOR EACH ROW
BEGIN
    INSERT INTO order_sequence VALUES (NULL);
    SET @last_id = LAST_INSERT_ID();
    SET NEW.Order_ID = CONCAT('ORD', LPAD(@last_id, 7, '0'));
    IF @last_id >= 100000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Order_IDs available';
    END IF;
END;
$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER order_item_linenumber
BEFORE INSERT ON ORDER_ITEM
FOR EACH ROW
BEGIN
    INSERT INTO order_item_sequence VALUES (NULL);
    SET @last_id = LAST_INSERT_ID();
    SET NEW.Item_line_number = CONCAT('LNU', LPAD(@last_id, 7, '0'));
    IF @last_id >= 100000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Order_item_linenumber_IDs available';
    END IF;
END;
$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER seller_id_sequence
BEFORE INSERT ON USER
FOR EACH ROW
BEGIN
    -- INSERT INTO seller_id_sequence VALUES (NULL);
    
    IF  new.Boolean_Seller = TRUE THEN
		INSERT INTO seller_id_sequence VALUES (NULL);
		SET @last_id = LAST_INSERT_ID();
		SET NEW.Seller_ID = CONCAT('SEL', LPAD(@last_id, 6, '0'));
	END IF;
    
	IF @last_id >= 100000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Seller_IDs available';
    END IF;
END;
$$
DELIMITER ;


DELIMITER $$
CREATE TRIGGER seller_update_id_sequence
BEFORE UPDATE ON USER
FOR EACH ROW
BEGIN
    -- INSERT INTO seller_id_sequence VALUES (NULL);
    
    IF  old.Boolean_Seller = FALSE and new.Boolean_Seller = TRUE THEN
		INSERT INTO seller_id_sequence VALUES (NULL);
		SET @last_id = LAST_INSERT_ID();
		SET NEW.Seller_ID = CONCAT('SEL', LPAD(@last_id, 6, '0'));
	END IF;
    
	IF @last_id >= 100000 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No more Seller_IDs available';
    END IF;
END;
$$
DELIMITER ;


DELIMITER $$
CREATE TRIGGER check_age_before_insert 
BEFORE INSERT ON USER
FOR EACH ROW
BEGIN
    IF NEW.Date_of_Birth >= CURDATE() - INTERVAL 15 YEAR THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'User must be at least 16 years old.';
    END IF;
END$$
DELIMITER ;

DELIMITER $$

CREATE TRIGGER check_order_dates 
BEFORE INSERT ON ORDER_TABLE
FOR EACH ROW
BEGIN
    IF NEW.Creation_date > CURDATE() THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Creation date cannot be in the future.';
    END IF;
    IF NEW.Creation_date >= NEW.Expected_date THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Expected date must be after creation date.';
    END IF;
END$$
DELIMITER ;

DELIMITER $$

CREATE TRIGGER update_check_order_dates 
BEFORE UPDATE ON ORDER_TABLE
FOR EACH ROW
BEGIN
    IF NEW.Creation_date > CURDATE() THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Creation date cannot be in the future.';
    END IF;
    IF NEW.Creation_date >= NEW.Expected_date THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Expected date must be after creation date.';
    END IF;
END$$
DELIMITER ;



DELIMITER $$

CREATE TRIGGER check_time_dates 
BEFORE INSERT ON TIME
FOR EACH ROW
BEGIN
    IF NEW.Start_date > CURDATE() THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Start date cannot be in the future.';
    END IF;
    IF NEW.End_date <= NEW.Start_date THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'End date must be after start date.';
    END IF;
END$$

DELIMITER ;

DELIMITER $$

CREATE TRIGGER check_admin_level 
BEFORE INSERT ON CHECKING_OTHER_WORK
FOR EACH ROW
BEGIN
    DECLARE checking_level ENUM('level_a', 'level_b', 'level_c');
    DECLARE checked_level ENUM('level_a', 'level_b', 'level_c');
    
    -- Get the level of the Admin checking
    SELECT Level INTO checking_level FROM ADMIN WHERE Account_ID = NEW.Account_ID_Check;
    
    -- Get the level of the Admin being checked
    SELECT Level INTO checked_level FROM ADMIN WHERE Account_ID = NEW.Account_ID_Be_Checked;
    
    -- Compare the levels
    IF checking_level < checked_level THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'The level of the Admin checking must be greater than or equal to the level of the Admin being checked.';
    END IF;
    
    IF checked_level < 'level_a' OR checking_level > 'level_c' THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Invalid admin level detected.';
    END IF;
END$$

DELIMITER ;

DELIMITER $$

CREATE TRIGGER update_product_prices
Before Insert ON PRODUCT 
FOR EACH ROW
BEGIN
    SET new.Discounted_Price = new.Product_price - (new.Product_price * (new.Discount / 100));
END$$

DELIMITER ;

DELIMITER $$

CREATE TRIGGER insert_order_item_prices
BEFORE INSERT ON ORDER_ITEM
FOR EACH ROW
BEGIN

    select a.Discounted_Price into @Dis_price from Product as a where a.Product_ID = new.Product_ID;
    
    Set new.Full_Discounted_Price = @Dis_price * new.Quantity;

END$$

DELIMITER ;

DELIMITER $$

CREATE TRIGGER insert_product_cart_quantity
AFTER INSERT ON PRODUCT_CART
FOR EACH ROW
BEGIN    
    -- Update the corresponding row in CART table
    UPDATE CART 
	SET Quantity = COALESCE((SELECT SUM(Quantity) FROM PRODUCT_CART WHERE Cart_ID = new.Cart_ID), 0)
    WHERE Cart_ID = NEW.Cart_ID;
END$$

DELIMITER ;


DELIMITER $$

CREATE TRIGGER delete_product_cart_quantity
AFTER DELETE ON PRODUCT_CART
FOR EACH ROW
BEGIN    
    -- Update the corresponding row in CART table
    UPDATE CART 
    -- SET Quantity = (SELECT COALESCE(SUM(Quantity), 0) FROM PRODUCT_CART WHERE Cart_ID = old.Cart_ID group by Cart_ID = old.Cart_ID limit 1)
     SET Quantity = COALESCE((SELECT SUM(Quantity) FROM PRODUCT_CART WHERE Cart_ID = old.Cart_ID), 0)
    WHERE Cart_ID = old.Cart_ID;
END$$

DELIMITER ;


DELIMITER $$

CREATE TRIGGER insert_into_cart_after_user_insert
AFTER INSERT ON USER
FOR EACH ROW
BEGIN
	DECLARE last_id INT;
    IF NEW.Boolean_Customer = TRUE THEN
		SELECT MAX(id) INTO last_id FROM sequence;
        SET @temp = CONCAT('CART', LPAD(last_id, 6, '0'));
        INSERT INTO CART (Cart_ID, Quantity, Account_ID) VALUES (@temp, 0, NEW.Account_ID);
    END IF;
END$$

DELIMITER ;


DELIMITER $$

CREATE TRIGGER insert_into_order_table
AFTER INSERT ON ORDER_ITEM
FOR EACH ROW
BEGIN
    DECLARE total_price DECIMAL(10, 2);

    -- Calculate total price for the order
    SELECT SUM(Full_Discounted_Price) INTO total_price
    FROM ORDER_ITEM
    WHERE Order_ID = NEW.Order_ID;

    -- Update the total_price in the ORDER_TABLE
    UPDATE ORDER_TABLE
    SET total_price = total_price
    WHERE Order_ID = NEW.Order_ID;
END$$

DELIMITER ;


-- Create functions
DELIMITER $$

CREATE FUNCTION CalculateOrderTotalPrice(orderid CHAR(10)) RETURNS DECIMAL(10, 2)
deterministic
BEGIN
    DECLARE total_price DECIMAL(10, 2);
    
    SELECT SUM(Full_Discounted_Price) INTO total_price
    FROM ORDER_ITEM
    WHERE Order_ID = orderid;
    
    RETURN total_price;
END$$

DELIMITER ;

DELIMITER $$

CREATE FUNCTION CalculateCartTotalPrice(cart CHAR(10)) RETURNS DECIMAL(10, 2)
deterministic
BEGIN
    DECLARE total_price DECIMAL(10, 2);
    
    SELECT SUM(a.Quantity * b.Discounted_Price) INTO total_price
    FROM PRODUCT_CART a join PRODUCT b on a.Product_ID = b.Product_ID
    WHERE a.Cart_ID = cart;
    
    RETURN total_price;
END$$

DELIMITER ;

DELIMITER $$

CREATE FUNCTION GetAverageProductRating(product CHAR(10)) RETURNS DECIMAL(5, 2)
deterministic
BEGIN
    DECLARE avg_rating DECIMAL(5, 2);
    
    SELECT AVG(Rating) INTO avg_rating
    FROM RATE
    WHERE Product_ID = product;
    
    RETURN avg_rating;
END$$

DELIMITER ;

DELIMITER $$
CREATE FUNCTION CalculateShippingFee(company CHAR(10), V VARCHAR(17)) RETURNS DECIMAL(10, 2)
deterministic
BEGIN
	DECLARE d DECIMAL(10, 2);
	DECLARE total_fee DECIMAL(10, 2);
    
	Select Distance into d from SHIPPED_BY where Company_ID = company and Vin = V;
    
    IF d <= 10 THEN
        SET total_fee = d * 3;
    ELSEIF d <= 20 THEN
        SET total_fee = (10 * 3) + ((d - 10) * 2.5);
    ELSEIF d <= 30 THEN
        SET total_fee = (10 * 3) + (10 * 2.5) + ((d - 20) * 2);
    ELSE
        SET total_fee = (10 * 3) + (10 * 2.5) + (10 * 2) + ((d - 30) * 1.5);
    END IF;
    
    RETURN total_fee;

END$$
DELIMITER ;

select CalculateShippingFee('DC10000001','VIN09876543211234');
-- Re-enable binary logging
SET sql_log_bin = 1;


DELIMITER $$

CREATE PROCEDURE ListOrdersForSeller(seller CHAR(9))
BEGIN
	SELECT Order_ID,Creation_date,Expected_date,total_price,Address,State
    FROM ORDER_TABLE 
    WHERE Seller_ID = seller
    ORDER BY Creation_date DESC;
END$$

DELIMITER ;

DELIMITER $$
CREATE PROCEDURE ListSellersBySalesRevenue(start_date DATE, end_date DATE)
BEGIN
    SELECT u.Seller_ID, CONCAT(u.FName, ' ', u.LName) AS Seller_Name, SUM(o.total_price) AS Total_Revenue
    FROM USER u
    JOIN ORDER_TABLE o ON u.Seller_ID = o.Seller_ID
    AND o.Creation_date > start_date AND o.Expected_date < end_date
    GROUP BY u.Seller_ID,u.FNAME,u.LNAME
    ORDER BY Total_Revenue DESC;
END$$
DELIMITER ;

DELIMITER $$

CREATE PROCEDURE UpdateOrderDates(
    IN orderID CHAR(10),
    IN newCreationDate DATE,
    IN newExpectedDate DATE,
    In newState Enum('waiting confirmation','Packaging','Shipping','Complete')
)
BEGIN
	SET FOREIGN_KEY_CHECKS = 0;

    UPDATE ORDER_TABLE
    SET Creation_Date = newCreationDate, Expected_date = newExpectedDate, State = newState
    WHERE Order_ID = orderID;
    
    SET FOREIGN_KEY_CHECKS = 1;
END $$

DELIMITER ;


DELIMITER $$

CREATE PROCEDURE UpdateUserName_Address_Phone (
    IN p_AccountID VARCHAR(9),
    IN p_NewAddress VARCHAR(255),
    IN phone CHAR(10),
    In emailling varchar(100)
)
BEGIN
	SET FOREIGN_KEY_CHECKS = 0;

    UPDATE USER
    SET Address = p_NewAddress , Phone_Number = phone, Email = emailling
    WHERE Account_ID = p_AccountID;
    
    SET FOREIGN_KEY_CHECKS = 1;
END$$

DELIMITER ;


CREATE VIEW Cart_of_Customer AS
SELECT
    Concat(a.LNAME, ' ',a.FNAME) as Full_Name,Email,a.Address,b.Cart_ID,b.Quantity,CalculateCartTotalPrice(b.Cart_ID) as Total_Price_need_to_pay
FROM
    User a join Cart b on a.Account_ID = b.Account_ID
Order by Total_Price_need_to_pay desc;


CREATE VIEW Product_RATE AS
SELECT
    a.Product_ID,
    a.Product_Name,
    a.Product_price,
    GetAverageProductRating(a.Product_ID) AS Average_Rating,
    c.Image_URL
FROM
    Product a
JOIN Rate b ON a.Product_ID = b.Product_ID
JOIN PRODUCT_IMAGE c ON a.Product_ID = c.Product_ID
WHERE
    c.Image_URL LIKE '%\_01.png'
GROUP BY
    a.Product_ID, a.Product_Name, c.Image_URL
ORDER BY
    Average_Rating DESC;

select * from Product_RATE;

	set foreign_key_checks = 0;
	use e_commerce;
	-- Inserting data into the USER table
	-- Account_ID will be generated automatically by the trigger
	INSERT INTO USER (Phone_Number, Address, FName, LName, Boolean_Customer, Boolean_Seller, Date_of_Birth, Email,Account_password)
	VALUES ('1234567890', '268 Ly Thuong Kiet, District 10, Ho Chi Minh City', 'Quoc Cuong', 'Pham', TRUE, FALSE, '1990-01-01', 'cuong.phamquoc@gmail.com','1234567890'),
		   ('9876543210', 'Campus of Ho Chi Minh City National University, Di An, Bình Dương', 'Tien Thinh', 'Nguyen', TRUE, TRUE, '1988-05-15', 'thinh.nguyentien@gmail.com','1234567890'),
		   ('5551234567', 'School of Computer Science and Engineering Building K17, UNSW Sydney, NSW 2052', 'Hua Phung', 'Nguyen', TRUE, TRUE, '1995-09-20', 'phung.nguyenhua@gmail.com','1234567890'),
		   ('9998887776', 'Campus of Ho Chi Minh City National University, Di An, Bình Dương', 'Ngoc Thinh', 'Tran', TRUE, TRUE, '1982-11-30', 'thinh.tranngoc@gmail.com','1234567890'),
		   ('3332221110', '268 Ly Thuong Kiet, District 10, Ho Chi Minh City', 'Tuan Anh', 'Tran', TRUE, FALSE, '1976-07-10', 'anh.trantuan@gmail.com','1234567890'),
		   ('0792040233', 'Broerstraat 5, 9712 CP Groningen, Netherlands', 'An Khuong', 'Nguyen', TRUE, FALSE, '1979-01-01', 'khuong.nguyenan@gmail.com','1234567890');

	-- Inserting data into the ADMIN table
	INSERT INTO ADMIN (Phone_Number, Address, FName, LName, Level)
	VALUES ('4567891230', '268 Ly Thuong Kiet, District 10, Ho Chi Minh City', 'Trong Thuc', 'Phung', 'level_a'),
		   ('1593574561', '268 Ly Thuong Kiet, District 10, Ho Chi Minh City', 'Thai Thanh', 'Le', 'level_b'),
		   ('9856325612', '268 Ly Thuong Kiet, District 10, Ho Chi Minh City', 'Tan Thi', 'Pham', 'level_c'),
		   ('9876543210', 'Campus of Ho Chi Minh City National University, Di An, Bình Dương', 'Tien Thinh', 'Nguyen', 'level_a'),
		   ('5551234567', 'School of Computer Science and Engineering Building K17, UNSW Sydney, NSW 2052', 'Hua Phung', 'Nguyen','level_a'),
		   ('9998887776', 'Campus of Ho Chi Minh City National University, Di An, Bình Dương', 'Ngoc Thinh', 'Tran','level_a');
INSERT INTO USER(Phone_number,address,FName,LName,Boolean_Customer,Boolean_Seller,Date_of_Birth,Email,User_ID,Account_password)
values ('0798944343','497 Hoa hao Phuong 7 Quan 10','Nguyễn','Hưng',true,true,'2004-09-10','hung.nguyen100904@hcmut.edu.vn','bbfc3cca-4660-4acf-86ab-fc8fd3eb0332','1234567890'),
	   ('0798944343','497 Hoa hao Phuong 7 Quan 10','Nguyễn','Hùng',true,false,'2004-09-10','nvh100904@gmail.com','4efd2254-f6f4-4be6-bf62-687dd61a3c06','1234567890');       

	-- Inserting data into the CHECKING_OTHER_WORK table
	INSERT INTO CHECKING_OTHER_WORK (Account_ID_Check, Account_ID_Be_Checked)
	VALUES ('ADM000002', 'ADM000001'),
		   ('ADM000003', 'ADM000001'),
		   ('ADM000003', 'ADM000003');

	-- Inserting data into the PRODUCT table
	INSERT INTO PRODUCT (Product_price, Product_Name, Discount, Seller_ID)
	VALUES (99.99, 'Smartphone', 5.00, 'SEL000001'),
		   (49.99, 'Headphones', 10.00, 'SEL000001'),
		   (299.99, 'Laptop', 0.00, 'SEL000002'),
		   (19.99, 'Mouse', 0.00, 'SEL000003'),
		   (149.99, 'Tablet', 8.00, 'SEL000002');
           INSERT INTO PRODUCT (Product_price, Product_Name,Discount, Seller_ID, Description)
values (554,"Asus VivoBook 15 X1502ZA",0.3,"SEL000003","Laptop Asus Vivobook 15 i5-1240P/8GB/512GB/Win11 (X1502ZA- BQ127W) toàn diện từ trong ra ngoài với hiệu năng mạnh mẽ và vẻ ngoài hết mực cuốn hút. Minh chứng cho điều này là vẻ ngoài sang trọng nhờ lớp vỏ phủ màu Xanh Dương Đậm thanh lịch. Tổng thể máy thì mỏng nhẹ chỉ khoảng 1.7 kg nhưng vẫn đảm bảo độ chắc chắn để bạn an tâm sử dụng lâu dài."),
	   (3202,"Laptop MSI Stealth 16 Mercedes AMG",0.0,"SEL000003","Laptop MSI Stealth 16 Mercedes AMG i9-13900H/32GB/2TB/Win11 (A13VG-289VN) là 'siêu phẩm' laptop gaming phiên bản giới hạn được tạo ra trên sự hợp tác giữa thương hiệu MSI và hãng xe đua nổi tiếng Mercedes-AMG Motorsport. MSI Stealth 16 Mercedes-AMG mang trong mình những đặc trưng tinh hoa của 2 thương hiệu đó là sự tinh xảo trong từng chi tiết thiết kế, tạo nên diện mạo hết mực đẳng cấp bên ngoài. Và bên trong là sức mạnh hiệu năng đỉnh cao được cung cấp bởi con chip Intel Core i9 Gen 13, kết hợp với card đồ họa NVIDIA® GeForce RTX™ 4070 Laptop cùng hàng loạt trang bị cao cấp khác, mang đến một thiết bị 'bất khả chiến bại' từ trong ra ngoài để người dùng có được trải nghiệm đẳng cấp trong mọi tác vụ, dù là chiến các tựa game cấu hình nặng với mức đồ họa cao, hay các tác vụ thiết kế đồ họa, render video khó nhằn. "),
	   (138355,"Tivi Micro LED Samsung 4K 110 inch MNA110MS1ACXXV",0.1,"SEL000003","Tivi Micro LED Samsung 4K 110 inch MNA110MS1ACXXV với kích cỡ màn hình cực lớn lên tới 110 inch cho bạn trải nghiệm nội dung được rộng mở hơn, mang đến tầm nhìn lớn hơn, chi tiết hơn và có chiều sâu hơn tạo cho bạn cảm giác như đang có mặt trực tiếp tại sân vận động hay nhà hát. Bên cạnh đó, thiết kế gần như tràn viền với đường nét tinh tế, thanh mảnh toát lên vẻ sang trọng, tạo điểm nhấn cho không gian thêm phần hiện đại. Chẳng những thế, tivi còn trang bị công nghệ góc nhìn siêu rộng lên đến 160° để người dùng có thể thoải mái xem ở mọi góc độ mà không phải lo ngại bị chói lóa hay biến đổi màu sắc."),
	   (35191,"Smart Tivi OLED LG 4K 97 inch OLED97G2PSA.ATV",0.1,"SEL000004","Smart Tivi OLED LG 4K 97 inch OLED97G2PSA.ATV giúp mọi không gian trưng bày trở nên sang trọng, đẹp rực rỡ với thiết kế tinh tế, kiểu dáng thanh lịch. Đặc biệt, 4 cạnh viền mỏng tạo cảm giác xem liền mạch tăng cảm giác lôi cuốn và tập trung ở từng khung hình hiển thị. Sản phẩm tạo nên một cột mốc mới trong thiết kế màn hình siêu mỏng, LG OLED G2 không chỉ gắn lên tường nhà bạn mà ngay cả khi đã tắt thì màn hình sẽ hiển thị những tác phẩm nghệ thuật với kết cấu và màu sắc cực kỳ chân thực. Độ rộng 97 inch, độ phân giải màn hình 4K OLED mang đến góc nhìn rộng hơn, những thước phim sắc nét chưa từng có."),
       (4745,"Panasonic Inverter 650 lít NR-WY720ZMMV",0.13,"SEL000004","Tủ Lạnh Panasonic Inverter Prime+ Edition 650 lít NR-WY720ZMMV là dòng tủ Multi Doors cao cấp bật nhất hiện nay của thương hiệu Panasonic vừa mới được ra mắt. Chiếc tủ lạnh này không chỉ sở hữu thiết kế hết mực sang trọng bên ngoài với tổng 6 cửa, kết hợp cùng mặt Gương Đen bóng bẩy, sành điệu; mà 'siêu phẩm' này còn được nhà Panasonic ưu ái tích hợp bên trong hàng loạt công nghệ bảo quản thực phẩm ưu việt nhằm mang đến trải nghiệm tối ưu cho người dùng. Đặc biệt nhất phải kể đến là công nghệ nanoe ™ X được nghiên cứu và phát triển độc quyền bởi thương hiệu Panasonic."),
       (2293,"Máy giặt sấy LG Inverter WT2517NHEG 25/17kg",0.23,"SEL000004","Máy giặt sấy LG Inverter WT2517NHEG 25/17kg là dòng tháp giặt sấy WashTower™ thế hệ mới tích hợp 2 trong 1, vừa có chức năng giặt, vừa có thể sấy khô tiện lợi. Máy có khối lượng giặt lớn đến 25 kg, khối lượng sấy đến 17 kg, thích hợp gia đình có nhiều người. Đặc biệt, với sự kết hợp màu sắc độc đáo Xanh Lá - Be, WashTower™ đẹp như thể một món đồ trang trí nội thất, tô điểm thêm không gian sinh sống nhà bạn. "),
       (1316,"Máy lạnh Daikin Inverter 2.5 HP FTKY60WVMV",0.05,"SEL000003","Máy lạnh Daikin Inverter 2.5 HP FTKY60WVMV sở hữu khả năng làm lạnh hiệu quả cùng nhiều công nghệ nổi bật như: công nghệ lọc khí Streamer, phin lọc Enzyme Blue kết hợp PM2.5 cho không khí mát lành sạch khuẩn, mắt thần thông minh tiêu chuẩn giúp tiết kiệm điện năng, Luồng gió Coanda và chức năng Làm lạnh nhanh Powerful cho cảm giác thoải mái tối đa,..."),
       (1661,"iRobot Roomba Combo j9 Plus",0.1,"SEL000004","Sản phẩm iRobot Roomba Combo j9 Plus không chỉ gây ấn tượng bởi thiết kế sang trọng, đẳng cấp từ thương hiệu Mỹ, dòng Combo j9+ còn mang đến khả năng làm sạch mạnh mẽ, giúp bạn rảnh tay hơn bao giờ hết với hệ điều hành iRobot OS thông minh, cảm biến Dirt Detective nhạy bén cùng hệ thống làm sạch 4 trong 1 tiên tiến. "),
       (4938,"Ghế massage Poongsan MCP-806",0.0,"SEL000004","Ghế massage có thiết kế dạng ôm trọn lưng, hông để massage toàn diện cả cơ thể. Công nghệ massage 4D với con lăn massage chuyển động đa chiều cho bạn cảm giác thoải mái. 24 bài tập massage tự động chuyên sâu để bạn tận hưởng cảm giác như được chuyên gia trị liệu. 5 chức năng massage tự chọn từng vùng, 6 bài tập massage thật như người."),
       (2804,"Máy pha cà phê Delonghi ECAM650.85.MS",0.23,"SEL000004","Máy pha cà phê màn hình màu, cảm ứng TFT 4,3” dễ dàng sử dụng và tương tác. Pha chế nhiều loại thức uống khác nhau nhờ chức năng Multibeverage. Chức năng Tea điều chỉnh nhiệt độ nước lý tưởng để tạo ra tách trà chuẩn vị nhất. Công thức cà phê và sữa đa dạng, dễ dàng tùy chỉnh phù hợp sở thích cá nhân.Bình sữa với thân vỏ kép cách nhiệt giúp giữ lạnh sữa lâu hơn.Hệ thống “LatteCrema” độc quyền tạo nên một ly cappuccino thơm ngon.");


	-- Inserting data into the CART table
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000001', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000002', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000003', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000004', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000005', 5);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000006', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000007', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000008', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000009', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000010', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000011', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000012', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000013', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000014', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000001', 'PRO0000015', 2);

INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000001', 5);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000002', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000003', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000004', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000005', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000006', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000007', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000008', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000009', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000010', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000011', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000012', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000013', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000014', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000002', 'PRO0000015', 5);

INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000001', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000002', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000003', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000004', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000005', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000006', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000007', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000008', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000009', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000010', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000011', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000012', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000013', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000014', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000003', 'PRO0000015', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000001', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000002', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000003', 5);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000004', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000005', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000006', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000007', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000008', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000009', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000010', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000011', 5);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000012', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000013', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000014', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000004', 'PRO0000015', 4);

INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000001', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000002', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000003', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000004', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000005', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000006', 5);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000007', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000008', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000009', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000010', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000011', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000012', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000013', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000014', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000005', 'PRO0000015', 8);

INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000001', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000002', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000003', 1);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000004', 6);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000005', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000006', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000007', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000008', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000009', 5);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000010', 10);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000011', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000012', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000013', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000014', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000006', 'PRO0000015', 5);

INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000001', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000002', 7);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000003', 8);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000004', 9);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000005', 15);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000006', 17);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000007', 24);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000008', 11);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000009', 2);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000007', 'PRO0000010', 6);

INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000008', 'PRO0000011', 43);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000008', 'PRO0000012', 23);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000008', 'PRO0000013', 4);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000008', 'PRO0000014', 3);
INSERT INTO PRODUCT_CART (Cart_ID, Product_ID, Quantity) VALUES ('CART000008', 'PRO0000015', 14);
	-- Inserting data into the ORDER_TABLE table
	INSERT INTO ORDER_TABLE (Creation_date, Expected_date, Cart_ID, State,Seller_ID,Address,total_price)
	VALUES ('2024-04-01', '2024-04-10', 'CART000001', 'waiting confirmation','SEL000003','268 Ly Thuong Kiet, District 10, Ho Chi Minh City',0),
		   ('2024-04-02', '2024-04-11', 'CART000002', 'Shipping','SEL000003','Campus of Ho Chi Minh City National University, Di An, Bình Dương',0),
		   ('2024-04-03', '2024-04-12', 'CART000003', 'Packaging','SEL000003','School of Computer Science and Engineering Building K17, UNSW Sydney, NSW 2052',0),
		   ('2024-04-04', '2024-04-13', 'CART000004', 'Complete','SEL000004','Campus of Ho Chi Minh City National University, Di An, Bình Dương',0),
		   ('2024-04-05', '2024-04-14', 'CART000005', 'waiting confirmation','SEL000003','268 Ly Thuong Kiet, District 10, Ho Chi Minh City',0),
           ('2024-04-06', '2024-04-14', 'CART000007', 'waiting confirmation','SEL000003','497 Hoa hao Phuong 7 Quan 10',0),
           ('2024-04-07', '2024-04-14', 'CART000007', 'Complete','SEL000004','497 Hoa hao Phuong 7 Quan 10',0),
           ('2024-04-01', '2024-04-12', 'CART000007', 'Packaging','SEL000004','497 Hoa hao Phuong 7 Quan 10',0),
           ('2024-04-08', '2024-04-14', 'CART000008', 'waiting confirmation','SEL000003','497 Hoa hao Phuong 7 Quan 10',0),
           ('2024-04-08', '2024-04-14', 'CART000008', 'Packaging','SEL000003','497 Hoa hao Phuong 7 Quan 10',0),
           ('2024-04-08', '2024-04-14', 'CART000008', 'Complete','SEL000004','497 Hoa hao Phuong 7 Quan 10',0);

	-- Inserting data into the ORDER_ITEM table
	INSERT INTO ORDER_ITEM (Order_ID, Quantity, Special_option, Product_ID)
	VALUES ('ORD0000001', 2, 'Gift Wrapping', 'PRO0000001'),
		   ('ORD0000002', 1,'Customization', 'PRO0000002'),
		   ('ORD0000003', 3, 'Color/Size Variants', 'PRO0000003'),
		   ('ORD0000004', 1, 'Gift Wrapping', 'PRO0000004'),
		   ('ORD0000005', 2, 'Express Shipping', 'PRO0000005'),
           ('ORD0000006', 3, 'Gift Wrapping', 'PRO0000004'),
           ('ORD0000006', 2, 'Warranty Extension', 'PRO0000006'),
           ('ORD0000006', 1, 'Gift Wrapping', 'PRO0000007'),
           ('ORD0000007', 2, 'Color/Size Variants', 'PRO0000009'),
           ('ORD0000007', 2, 'Color/Size Variants', 'PRO0000010'),
           ('ORD0000007', 2,'Gift Wrapping', 'PRO0000011'),
           ('ORD0000008', 2, 'Customization', 'PRO0000009'),
           ('ORD0000008', 1, 'Color/Size Variants', 'PRO0000013'),
           ('ORD0000009', 2,  'Gift Wrapping', 'PRO0000012'),
           ('ORD0000009', 3, 'Color/Size Variants', 'PRO0000008'),
		   ('ORD0000010', 2, 'Gift Wrapping', 'PRO0000004'),
           ('ORD0000010', 3,  'Color/Size Variants', 'PRO0000007'),
		   ('ORD0000011', 3,  'Gift Wrapping', 'PRO0000014'),
           ('ORD0000011', 3, 'Warranty Extension', 'PRO0000015');
           

	-- Inserting data into the PAYMENT_ORDER table
	INSERT INTO PAYMENT_ORDER (Order_ID, A_Payment_method)
	VALUES ('ORD0000001', 'In_cash'),
		   ('ORD0000002', 'Credit_card'),
		   ('ORD0000003', 'Debit_card'),
		   ('ORD0000004', 'PayPal'),
		   ('ORD0000005', 'In_cash');

	-- Inserting data into the RATE table
	INSERT INTO RATE (Account_ID, Product_ID, Rating)
	VALUES ('ACC000001', 'PRO0000001', 4),  
		   ('ACC000002', 'PRO0000002', 5),  
		   ('ACC000003', 'PRO0000003', 4),  
		   ('ACC000003', 'PRO0000004', 3),  
		   ('ACC000005', 'PRO0000005', 5);  

	-- Inserting data into the ADVERTISEMENT_COMPANY table
	INSERT INTO ADVERTISEMENT_COMPANY (Company_ID, Company_Type)
	VALUES ('C100000001', 'TV'),
		   ('C100000002', 'YouTube'),
		   ('C100000003', 'Social_media');

	-- Inserting data into the TV_ADVERTISEMENT table
	INSERT INTO TV_ADVERTISEMENT (TV_ad_id, Fee, Time_on_site, Company_ID)
	VALUES ('TVA1000001', 500.00, 30, 'C10000001'),
		   ('TVA1000002', 1000.00, 60, 'C10000001'),
		   ('TVA1000003', 750.00, 45, 'C10000001');

	-- Inserting data into the YOUTUBE_ADVERTISEMENT table
	INSERT INTO YOUTUBE_ADVERTISEMENT (Youtube_ad_id, Fee, Frequency_on_video, Company_ID)
	VALUES ('YTA1000001', 300.00, 20, 'C10000002'),
		   ('YTA1000002', 200.00, 15, 'C10000002'),
		   ('YTA1000003', 400.00, 25, 'C10000002');

	-- Inserting data into the SOCIAL_MEDIA_ADVERTISEMENT table
	INSERT INTO SOCIAL_MEDIA_ADVERTISEMENT (Social_media_ad_id, Fee, Frequency_on_social_media, Company_ID)
	VALUES ('SMA1000001', 150.00, 100, 'C10000003'),
		   ('SMA1000002', 200.00, 120, 'C10000003'),
		   ('SMA1000003', 100.00, 80, 'C10000003');

	-- Inserting data into the BOOKING table
	INSERT INTO BOOKING (Seller_ID, Company_ID)
	VALUES ('SEL000001', 'C100000001'),  
		   ('SEL000002', 'C100000002'),  
		   ('SEL000002', 'C100000003'),  
		   ('SEL000003', 'C100000001'),  
		   ('SEL000003', 'C100000003');  

	-- Inserting data into the TIME table
	INSERT INTO TIME (Seller_ID, Company_ID, Start_date, End_date)
	VALUES ('SEL000001', 'C100000001', '2024-04-01', '2024-04-10'),  
		   ('SEL000002', 'C100000002', '2024-04-02', '2024-04-11'), 
		   ('SEL000002', 'C100000003', '2024-04-03', '2024-04-12'),  
		   ('SEL000003', 'C100000001', '2024-04-04', '2024-04-13'),  
		   ('SEL000003', 'C100000003', '2024-04-05', '2024-04-14');  

	-- Inserting data into the DELIVERY_COMPANY table
	INSERT INTO DELIVERY_COMPANY (Company_ID, Company_Name)
	VALUES ('DC10000001', 'Fast Delivery Inc.'),
		   ('DC10000002', 'Quick Ship'),
		   ('DC10000003', 'Speedy Courier');

	-- Inserting data into the VEHICLE table
	INSERT INTO VEHICLE (Vin, Type, Capacity)
	VALUES ('VIN12345678901234', 'Truck', 100),
		   ('VIN98765432109876', 'Van', 50),
		   ('VIN54321678901234', 'Bike', 1),
		   ('VIN09876543211234', 'Car', 5),
		   ('VIN43210987654321', 'Scooter', 1);

	-- Inserting data into the SHIPPED_BY table
	INSERT INTO SHIPPED_BY (Company_ID, Vin, Order_ID, Distance)
	VALUES ('DC10000001', 'VIN12345678901234', 'ORD0000001', 50.00),
		   ('DC10000002', 'VIN98765432109876', 'ORD0000002', 30.00),
		   ('DC10000003', 'VIN54321678901234', 'ORD0000003', 20.00),
		   ('DC10000001', 'VIN09876543211234', 'ORD0000004', 40.00),
		   ('DC10000002', 'VIN43210987654321', 'ORD0000005', 25.00);

	-- Inserting data into the REPORT table
	INSERT INTO REPORT (Order_Id, Account_ID_admin, Account_ID_seller, Date, Feedback)
	VALUES ('ORD0000001', 'ADM000001', 'SEL000001', '2024-04-10', 'Good service overall.'),
		   ('ORD0000002', 'ADM000001', 'SEL000001', '2024-04-11', 'Customer seemed satisfied.'),
		   ('ORD0000003', 'ADM000002', 'SEL000002', '2024-04-12', 'Prompt delivery.'),
		   ('ORD0000004', 'ADM000002', 'SEL000002', '2024-04-13', 'Product as described.'),
		   ('ORD0000005', 'ADM000003', 'SEL000003', '2024-04-14', 'Smooth transaction.');

	-- Inserting data into the CUSTOMER_CARE_SERVICE table
	INSERT INTO CUSTOMER_CARE_SERVICE (Account_ID_admin,Account_ID_seller, Experience)
	VALUES ('ADM000001', 'SEL000001', 'Satisfied customers.'),
		   ('ADM000002', 'SEL000002', 'Handled complaints effectively.'),
		   ('ADM000003', 'SEL000003', 'Experience in sales and support.');
		   
		   
	INSERT INTO RATE (Account_ID, Product_ID, Rating) VALUES 
    ('ACC000007','PRO0000006',5),
	('ACC000001', 'PRO0000006', 1),
	('ACC000002', 'PRO0000007', 2),
	('ACC000003', 'PRO0000008', 3),
	('ACC000004', 'PRO0000009', 4),
	('ACC000005', 'PRO0000010', 5),
	('ACC000006', 'PRO0000011', 1),
	('ACC000001', 'PRO0000012', 2),
	('ACC000002', 'PRO0000013', 3),
	('ACC000003', 'PRO0000014', 4),
	('ACC000004', 'PRO0000015', 5),
	('ACC000006', 'PRO0000006', 2),
	('ACC000001', 'PRO0000007', 3),
	('ACC000002', 'PRO0000008', 4),
	('ACC000003', 'PRO0000009', 5),
	('ACC000004', 'PRO0000010', 1),
	('ACC000005', 'PRO0000011', 2),
	('ACC000006', 'PRO0000012', 3),
	('ACC000001', 'PRO0000013', 4),
	('ACC000002', 'PRO0000014', 5),
	('ACC000003', 'PRO0000015', 1),
	('ACC000005', 'PRO0000006', 3),
	('ACC000006', 'PRO0000007', 4),
	('ACC000001', 'PRO0000008', 5),
	('ACC000002', 'PRO0000009', 1),
	('ACC000003', 'PRO0000010', 2),
	('ACC000004', 'PRO0000011', 3),
	('ACC000005', 'PRO0000012', 4);
	set foreign_key_checks = 1;

set foreign_key_checks = 0;


INSERT INTO PRODUCT_IMAGE (Product_ID,Image_URL)
values ("PRO0000001","/image/PRO0000001_01.png"),
       ("PRO0000001","/image/PRO0000001_02.png"),
       ("PRO0000001","/image/PRO0000001_03.png"),
       ("PRO0000001","/image/PRO0000001_04.png"),
	   ("PRO0000002","/image/PRO0000002_01.png"),
       ("PRO0000002","/image/PRO0000002_02.png"),
       ("PRO0000002","/image/PRO0000002_03.png"),
       ("PRO0000002","/image/PRO0000002_04.png"),
       ("PRO0000003","/image/PRO0000003_01.png"),
       ("PRO0000003","/image/PRO0000003_02.png"),
       ("PRO0000003","/image/PRO0000003_03.png"),
       ("PRO0000003","/image/PRO0000003_04.png"),
       ("PRO0000004","/image/PRO0000004_01.png"),
       ("PRO0000004","/image/PRO0000004_02.png"),
       ("PRO0000004","/image/PRO0000004_03.png"),
       ("PRO0000004","/image/PRO0000004_04.png"),
       ("PRO0000005","/image/PRO0000005_01.png"),
       ("PRO0000005","/image/PRO0000005_02.png"),
       ("PRO0000005","/image/PRO0000005_03.png"),
       ("PRO0000005","/image/PRO0000005_04.png"),
       ("PRO0000006","/image/PRO0000006_01.png"),
       ("PRO0000006","/image/PRO0000006_02.png"),
       ("PRO0000006","/image/PRO0000006_03.png"),
       ("PRO0000006","/image/PRO0000006_04.png"),
	   ("PRO0000007","/image/PRO0000007_01.png"),
       ("PRO0000007","/image/PRO0000007_02.png"),
       ("PRO0000007","/image/PRO0000007_03.png"),
       ("PRO0000007","/image/PRO0000007_04.png"),
       ("PRO0000008","/image/PRO0000008_01.png"),
       ("PRO0000008","/image/PRO0000008_02.png"),
       ("PRO0000008","/image/PRO0000008_03.png"),
       ("PRO0000008","/image/PRO0000008_04.png"),
       ("PRO0000009","/image/PRO0000009_01.png"),
       ("PRO0000009","/image/PRO0000009_02.png"),
       ("PRO0000009","/image/PRO0000009_03.png"),
       ("PRO0000009","/image/PRO0000009_04.png"),
       ("PRO0000010","/image/PRO0000010_01.png"),
       ("PRO0000010","/image/PRO0000010_02.png"),
       ("PRO0000010","/image/PRO0000010_03.png"),
       ("PRO0000010","/image/PRO0000010_04.png"),
       ("PRO0000011","/image/PRO0000011_01.png"),
       ("PRO0000011","/image/PRO0000011_02.png"),
       ("PRO0000011","/image/PRO0000011_03.png"),
       ("PRO0000011","/image/PRO0000011_04.png"),
       ("PRO0000012","/image/PRO0000012_01.png"),
       ("PRO0000012","/image/PRO0000012_02.png"),
       ("PRO0000012","/image/PRO0000012_03.png"),
       ("PRO0000012","/image/PRO0000012_04.png"),
       ("PRO0000013","/image/PRO0000013_01.png"),
       ("PRO0000013","/image/PRO0000013_02.png"),
       ("PRO0000013","/image/PRO0000013_03.png"),
       ("PRO0000013","/image/PRO0000013_04.png"),
       ("PRO0000014","/image/PRO0000014_01.png"),
       ("PRO0000014","/image/PRO0000014_02.png"),
       ("PRO0000014","/image/PRO0000014_03.png"),
       ("PRO0000014","/image/PRO0000014_04.png"),
       ("PRO0000015","/image/PRO0000015_01.png"),
       ("PRO0000015","/image/PRO0000015_02.png"),
       ("PRO0000015","/image/PRO0000015_03.png"),
       ("PRO0000015","/image/PRO0000015_04.png");



set foreign_key_checks = 1;

CREATE USER 'usertemp'@'%' IDENTIFIED BY 'h';

GRANT insert ON e_commerce.* TO 'usertemp'@'%';
GRANT SELECT ON e_commerce.PRODUCT TO 'usertemp'@'%';
GRANT SELECT ON e_commerce.CART TO 'usertemp'@'%';

-- CREATE VIEW restricted_user_view AS
-- SELECT * FROM e_commerce.USER WHERE Account_ID = 'ACC0000003';

-- GRANT SELECT ON e_commerce.restricted_user_view TO 'usertemp'@'%';

CREATE USER 'admin'@'%' IDENTIFIED BY 'h';

GRANT ALL privileges ON e_commerce.* TO 'admin'@'%';

FLUSH PRIVILEGES;

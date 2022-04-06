package main;

import hashdb.HashFile;
import hashdb.HashHeader;
import hashdb.Vehicle;
import misc.ReturnCodes;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class StudentFunctions {
    // Daniel Ferrer-Sosa (tfe646)

    /* NOTE: the RAF instances created and/or manipulated are never closed,
             I'm going to make the bold assumption Java's garbage collection is going to take care of this for me */

    /**
     * hashCreate
     * This funcAon creates a hash file containing only the HashHeader record.
     * • If the file already exists, return RC_FILE_EXISTS
     * • Create the binary file by opening it.
     * • Write the HashHeader record to the file at RBN 0.
     * • close the file.
     * • return RC_OK.
     */
    public static int hashCreate(String fileName, HashHeader hashHeader) throws IOException {
        File f = new File(fileName);

        // check if file exists
        if (f.exists()) {
            return ReturnCodes.RC_FILE_EXISTS;
        }
        else {
            // file didn't exist, we'll have to create it
            HashFile hf = new HashFile();
            RandomAccessFile raf = new RandomAccessFile(fileName, "rw");

            // set HashFile's attributes
            hf.setFile(raf);
            hf.setHashHeader(hashHeader);

            // a valid HashFile must contain a valid HashHeader
            raf.write(hf.getHashHeader().toByteArray());
            raf.read();

            return ReturnCodes.RC_OK;
        }
    }

    /**
     * hashOpen
     * This function opens an existing hash file which must contain a HashHeader record
     * , and sets the file member of hashFile
     * It returns the HashHeader record by setting the HashHeader member in hashFile
     * If it doesn't exist, return RC_FILE_NOT_FOUND.
     * Read the HashHeader record from file and return it through the parameter.
     * If the read fails, return RC_HEADER_NOT_FOUND.
     * return RC_OK
     */
    public static int hashOpen(String fileName, HashFile hashFile) {
        File f = new File(fileName);

        // when creating a new RAF, we can only open in "rw" mode which creates the file
        // a check if file exists BEFORE opening will allow us to return error and stop us from creating file
        if (!f.exists()) {
            return ReturnCodes.RC_FILE_NOT_FOUND;
        }

        RandomAccessFile raf;

        try {
            raf = new RandomAccessFile(fileName, "rw");

        } catch (FileNotFoundException e) {
            return ReturnCodes.RC_FILE_NOT_FOUND;
        }

        // validate HashHeader rec
        if(hashFile.getHashHeader().getRecSize() == 0) {
            return ReturnCodes.RC_HEADER_NOT_FOUND;
        }
        else {
            hashFile.setHashHeader(hashFile.getHashHeader());
        }

        hashFile.setFile(raf);

        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleInsert
     * This function inserts a vehicle into the specified file.
     * Determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If that location doesn't exist
     * OR the record at that location has a blank vehicleId (i.e., empty string):
     * THEN Write this new vehicle record at that location using writeRec.
     * If that record exists and that vehicle's szVehicleId matches, return RC_REC_EXISTS.
     * (Do not update it.)
     * Otherwise, return RC_SYNONYM. a SYNONYM is the same thing as a HASH COLLISION
     * Note that in program #2, we will actually insert synonyms.
     */
    public static int vehicleInsert(HashFile hashFile, Vehicle vehicle) {
        // we'll need another Vehicle obj for the duplicate rec validation
        Vehicle preProcVehicle = vehicle;

        int RBN = Main.hash(vehicle.getVehicleId(), hashFile.getHashHeader().getMaxHash());
        int rc = readRec(hashFile, RBN, vehicle);

        char[] vChars = vehicle.getVehicleId();

        // if record at RBN doesn't exist or vehicle id is returned empty, we'll write a new record
        if (rc == ReturnCodes.RC_LOC_NOT_FOUND || vChars.length == 0) {
            return writeRec(hashFile, RBN, vehicle);
        }

        // if the vehicleId returned is equal to the one we are trying to insert
        // it will mean the rec exists
        else if (rc == ReturnCodes.RC_OK && vChars == preProcVehicle.getVehicleId()) {
            return ReturnCodes.RC_REC_EXISTS;
        }

        return ReturnCodes.RC_SYNONYM;
    }

    /**
     * readRec(
     * This function reads a record at the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Read that record and return it through the vehicle parameter.
     * If the location is not found, return RC_LOC_NOT_FOUND.  Otherwise, return RC_OK.
     * Note: if the location is found, that does NOT imply that a vehicle
     * was written to that location.  Why?
      */
    public static int readRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        int RBA = rbn * hashFile.getHashHeader().getRecSize();
        byte[] vBytes = new byte[Vehicle.sizeOf()]; // we'll need to store the Vehicle
                                                   // record we read in some array of bytes

        try {
            // move file cursor and read rec
            hashFile.getFile().seek(RBA);
            hashFile.getFile().read(vBytes, 0, Vehicle.sizeOf());

            // a null bit at 2nd index means we didn't fund anything
            if (vBytes[1] == '\0') {
                return ReturnCodes.RC_LOC_NOT_FOUND;
            }

            // if we are here we found a valid record
            // pass it back to caller via param
            vehicle.fromByteArray(vBytes);


        } catch (IOException e) {
            return ReturnCodes.RC_LOC_NOT_FOUND;
        }

        return ReturnCodes.RC_OK;
    }

    /**
     * writeRec
     * This function writes a record to the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Write that record to the file.
     * If the write fails, return RC_LOC_NOT_WRITTEN.
     * Otherwise, return RC_OK.
     */
    public static int writeRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        int RBA = rbn * hashFile.getHashHeader().getRecSize();

        try {
            // move file cursor and write rec
            hashFile.getFile().seek(RBA);
            hashFile.getFile().write(vehicle.toByteArray(), 0, Vehicle.sizeOf());

        } catch (IOException e) {
            return ReturnCodes.RC_LOC_NOT_WRITTEN;
        }

        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleRead
     * This function reads the specified vehicle by its vehicleId.
     * Since the vehicleId was provided,
     * determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If the vehicle at that location matches the specified vehicleId,
     * return the vehicle via the parameter and return RC_OK.
     * Otherwise, return RC_REC_NOT_FOUND
     */
    public static int vehicleRead(HashFile hashFile, int rbn, Vehicle vehicle) {
        Vehicle procVehicle = new Vehicle();    // create processingVehicle to compare rec

        readRec(hashFile, rbn, procVehicle);

        // since Vehicle.getVehicleId() returns a char array, we'll use the Arrays class to compare
        // we'll know we have a match if the both vehicleIds are equal
        if (Arrays.equals(procVehicle.getVehicleId(), vehicle.getVehicleId())) {
            vehicle.fromByteArray(procVehicle.toByteArray());

            return ReturnCodes.RC_OK;
        }

        return ReturnCodes.RC_REC_NOT_FOUND;
    }
}

package com.example.a214010.address_214010;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by 214010 on 2016/11/21.
 */
public class AddressDB extends SQLiteOpenHelper {
    private static final String DB_NAME = "ccc.db";
    private static final int DB_VERSION = 1;
    public static final String TABLE_NAME = "address";
    public static final String _ID = "_id";
    public static final String NAME = "Name";
    public static final String AGE = "Age";
    public static final String ADDRESS = "Address";



    public AddressDB(Context context){
        super(context,DB_NAME,null,DB_VERSION);
    }
    @Override
    public void onCreate(SQLiteDatabase db) {
        String createTable = "CREATE TABLE " + TABLE_NAME + " ( " +
                _ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
               NAME + " TEXT, " + AGE + " TEXT, " + ADDRESS + " TEXT " + " )";
        db.execSQL(createTable);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }


}

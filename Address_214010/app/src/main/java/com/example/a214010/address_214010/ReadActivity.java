package com.example.a214010.address_214010;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

public class ReadActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.read);

        ListView myListView = (ListView)findViewById(R.id.listView);

        AddressDB helper = new AddressDB(this);
        SQLiteDatabase database = helper.getReadableDatabase();

        String[] columns ={"_id","Name","Age","Address"};
        String selection = null;
        String[] selectionArgs = null;
        String groupBy = null;
        String having = null;
        String orderBy = null;
        Cursor cursor=database.query("address",columns, selection, selectionArgs, groupBy, having, orderBy);
        ArrayList<String> items = new ArrayList<>();
        while (cursor.moveToNext()){
            int id=cursor.getInt(cursor.getColumnIndex("_id"));
            String name=cursor.getString(cursor.getColumnIndex("Name"));
            String age=cursor.getString(cursor.getColumnIndex("Age"));
            String address=cursor.getString(cursor.getColumnIndex("Address"));
            //Log.d("DB_TEST",String.valueOf(id+" "+name+""+age+""+address));

            items.add(id+" "+name+""+age+""+address);
        }
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                this,
                R.layout.support_simple_spinner_dropdown_item,
                items
        );

        myListView.setAdapter(adapter);

        cursor.close();
        database.close();
    }

    public void rback(View view){
        Intent intent = new Intent(getApplication(),MainActivity.class);
        startActivity(intent);
    }


}

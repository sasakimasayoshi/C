package com.example.a214010.address_214010;

import android.content.Intent;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class DeleteActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.delete);

        data();

    }
    public void data(){
        ListView myListView = (ListView) findViewById(R.id.dellist);

        final AddressDB helper = new AddressDB(this);
        final SQLiteDatabase database = helper.getReadableDatabase();

        String[] columns = {"_id", "Name", "Age", "Address"};
        String selection = null;
        String[] selectionArgs = null;
        String groupBy = null;
        String having = null;
        String orderBy = null;
        Cursor cursor = database.query("address", columns, selection, selectionArgs, groupBy, having, orderBy);
        ArrayList<String> items = new ArrayList<>();
        while (cursor.moveToNext()) {
            int id = cursor.getInt(cursor.getColumnIndex("_id"));
            String name = cursor.getString(cursor.getColumnIndex("Name"));
            String age = cursor.getString(cursor.getColumnIndex("Age"));
            String address = cursor.getString(cursor.getColumnIndex("Address"));
            //Log.d("DB_TEST",String.valueOf(id+" "+name+""+age+""+address));

            items.add(id + " " + name + "" + age + "" + address);
        }
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                this,
                R.layout.support_simple_spinner_dropdown_item,
                items
        );

        myListView.setAdapter(adapter);

        myListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            public void onItemClick(AdapterView<?> parent,
                                    View view, int pos, long id) {

                // 選択アイテムを取得
                ListView listView = (ListView) parent;
                String item = (String) listView.getItemAtPosition(pos);
                String item2 = String.valueOf("_id= " + 1);
                
                // 通知ダイアログを表示
                Toast.makeText(DeleteActivity.this,
                        item, Toast.LENGTH_LONG
                ).show();
            }
        });

        cursor.close();
        database.close();
    }

    public void deldata(View view){
        ListView myListView = (ListView) findViewById(R.id.dellist);
        final AddressDB helper = new AddressDB(this);
        final SQLiteDatabase database = helper.getReadableDatabase();


                try {
                    database.delete("address", "_id = "+1, null);
                } finally {
                    database.close();
                }

                /*String sql = "delete from address" + " where(_id=" + item + ");";
                try {
                    database.execSQL(sql);
                } catch (SQLException e) {
                    Log.e("ERROR", e.toString());
                }*/
                //database.delete("address", "_id = " + id, null);

    }

    public void dback(View view) {
        Intent intent = new Intent(getApplication(), MainActivity.class);
        startActivity(intent);
    }
}
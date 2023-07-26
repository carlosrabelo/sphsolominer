#include <Arduino.h>

void runTask1(void *name)
{
    Serial.print("\nTask1 started");
    while (true)
    {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void runTask2(void *name)
{
    Serial.print("\nTask2 started");
    while (true)
    {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void runTask3(void *name)
{
    Serial.print("\nTask3 started");
    while (true)
    {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.setTimeout(0);

    disableCore0WDT();

    Serial.print("\nSPH starting...");

    BaseType_t res1 = xTaskCreatePinnedToCore(runTask1, "Task1", 5000, NULL, 4, NULL, 1);
    BaseType_t res2 = xTaskCreatePinnedToCore(runTask2, "Task2", 20000, NULL, 3, NULL, 1);

    xTaskCreate(runTask3, "Task3A", 5000, NULL, 1, NULL);
    xTaskCreate(runTask3, "Task3B", 5000, NULL, 1, NULL);
}

void loop()
{
}

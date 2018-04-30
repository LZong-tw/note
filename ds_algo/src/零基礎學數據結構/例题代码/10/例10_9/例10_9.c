/*����ͷ�ļ�*/
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int DataType;           /*ջԪ�����Ͷ���*/
#include"SeqStack.h"
/*ͼ���ڽӱ����Ͷ���*/
typedef char VertexType[4];
typedef int InfoPtr;            /*����Ϊ���ͣ�Ϊ�˴��Ȩֵ*/
typedef int VRType;
#define MaxSize 50              /*��󶥵����*/
typedef enum {DG, DN, UG, UN} GraphKind; /*ͼ�����ͣ�����ͼ��������������ͼ��������*/
typedef struct ArcNode {        /*�߽������Ͷ���*/
    int adjvex;                 /*��ָ��Ķ����λ��*/
    InfoPtr* info;              /*����Ȩֵ*/
    struct ArcNode* nextarc;    /*ָʾ��һ����ö������ڽӵĶ���*/
} ArcNode;
typedef struct VNode {          /*ͷ�������Ͷ���*/
    VertexType data;            /*���ڴ洢����*/
    ArcNode* firstarc;          /*ָʾ��һ����ö����ڽӵĶ���*/
} VNode, AdjList[MaxSize];
typedef struct {                /*ͼ�����Ͷ���*/
    AdjList vertex;
    int vexnum, arcnum;         /*ͼ�Ķ�����Ŀ�뻡����Ŀ*/
    GraphKind kind;             /*ͼ������*/
} AdjGraph;
void BriefPath(AdjGraph G, int u, int v);
void PrintPath(int u, int v);
void DfsAllPath(AdjGraph* G, int u, int v);



void BriefPath(AdjGraph G, int u, int v)
/*��ͼG�дӶ���u������v��һ����·��*/
{
    int k, i;
    SeqStack S;
    ArcNode* p;
    int visited[MaxSize];
    int parent[MaxSize];        /*�洢�Ѿ����ʶ����ǰ������*/
    InitStack(&S);

    for (k = 0; k < G.vexnum; k++) { /*���ʱ�־��ʼ��*/
        visited[k] = 0;
    }

    PushStack(&S, u);           /*��ʼ������ջ*/
    visited[u] = 1;             /*���ʱ�־��Ϊ1*/

    while (!StackEmpty(S)) {    /*������ȱ���ͼ������·����parent�洢*/
        PopStack(&S, &k);
        p = G.vertex[k].firstarc;

        while (p != NULL) {
            if (p->adjvex == v) { /*����ҵ�����v*/
                parent[p->adjvex] = k;  /*����v��ǰ�����������k*/
                printf("����%s������%s��·���ǣ�", G.vertex[u].data, G.vertex[v].data);
                i = v;

                do {                    /*�Ӷ���v��ʼ��·���еĶ���������ջ*/
                    PushStack(&S, i);
                    i = parent[i];
                } while (i != u);

                PushStack(&S, u);

                while (!StackEmpty(S)) { /*�Ӷ���u��ʼ���u��v��·���Ķ���*/
                    PopStack(&S, &i);
                    printf("%s ", G.vertex[i].data);

                }

                printf("\n");
            } else if (visited[p->adjvex] ==
                       0) { /*���δ�ҵ�����v���ڽӵ�δ���ʹ��������Ѱ��*/
                visited[p->adjvex] = 1;
                parent[p->adjvex] = k;
                PushStack(&S, p->adjvex);
            }

            p = p->nextarc;
        }
    }
}

int LocateVertex(AdjGraph G, VertexType v)
/*����ͼ�ж����Ӧ��λ��*/
{
    int i;

    for (i = 0; i < G.vexnum; i++)
        if (strcmp(G.vertex[i].data, v) == 0) {
            return i;
        }

    return -1;
}
void CreateGraph(AdjGraph* G)
/*�����ڽӱ�洢�ṹ����������ͼN*/
{
    int i, j, k, w;
    VertexType v1, v2;                  /*������������v1��v2*/
    ArcNode* p;
    printf("������ͼ�Ķ�����,����(�Զ��ŷָ�): ");
    scanf("%d,%d", &(*G).vexnum, &(*G).arcnum);
    printf("������%d�������ֵ:", G->vexnum);

    for (i = 0; i < G->vexnum; i++) {   /*������洢��ͷ�����*/
        scanf("%s", G->vertex[i].data);
        G->vertex[i].firstarc = NULL;   /*��������Ķ�����Ϊ��*/
    }

    printf("������ߵ���������(�Կո���Ϊ�ָ�):\n");

    for (k = 0; k < G->arcnum; k++) {   /*����������*/
        scanf("%s%s", v1, v2);
        i = LocateVertex(*G, v1);
        j = LocateVertex(*G, v2);
        /*jΪ���iΪ���ߴ����ڽӱ�*/
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->info = (InfoPtr*)malloc(sizeof(InfoPtr));
        /*��pָ��Ľ����뵽�߱���*/
        p->nextarc = G->vertex[i].firstarc;
        G->vertex[i].firstarc = p;
        /*iΪ���jΪ���ߴ����ڽӱ�*/
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->info = NULL;
        p->nextarc = G->vertex[j].firstarc;
        G->vertex[j].firstarc = p;
    }

    (*G).kind = UG;
}
void DestroyGraph(AdjGraph* G)
/*��������ͼG*/
{
    int i;
    ArcNode* p, *q;

    for (i = 0; i < G->vexnum; ++i) { /*�ͷ�ͼ�еı߱���*/
        p = G->vertex[i].firstarc;  /*pָ��߱�ĵ�һ�����*/

        if (p != NULL) {            /*����߱�Ϊ�գ����ͷű߱�Ľ��*/
            q = p->nextarc;
            free(p);
            p = q;
        }
    }

    (*G).vexnum = 0;                /*����������Ϊ0*/
    (*G).arcnum = 0;                /*���ߵ���Ŀ��Ϊ0*/
}
void DisplayGraph(AdjGraph G)
/*ͼG���ڽӱ�����*/
{
    int i;
    ArcNode* p;
    printf("��ͼ����%d�����㣺", G.vexnum);

    for (i = 0; i < G.vexnum; i++) {
        printf("%s ", G.vertex[i].data);
    }

    printf("\nͼ�й���%d����:\n", 2 * G.arcnum);

    for (i = 0; i < G.vexnum; i++) {
        p = G.vertex[i].firstarc;

        while (p) {
            printf("(%s,%s) ", G.vertex[i].data, G.vertex[p->adjvex].data);
            p = p->nextarc;
        }

        printf("\n");
    }
}
void main()
{
    AdjGraph G;
    CreateGraph(&G);        /*�����ڽӱ�洢�ṹ����ͼG*/
    DisplayGraph(G);        /*�������ͼG*/
    BriefPath(G, 0, 4);     /*��ͼG�дӶ���a������e�ļ�·��*/
    DestroyGraph(&G);       /*����ͼG*/
}